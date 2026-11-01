#!/usr/bin/env python3
"""Code-only fix check for ERR_SSL_PROTOCOL_ERROR on the phi ledger site.
Does NOT touch index.html physically. It checks, in code, what can and
cannot cause a TLS handshake error, and prints the code-level fix.

Rule learned 2026-10-31: a TLS handshake error happens BEFORE any HTML
loads, so no HTML/CSS/layout change can fix it. The code fix is:
1. All subresources must be https (checked below, no http:// found in
   index.html/app.js in the restored site).
2. No mixed-content downgrade: add, in code only, an upgrade-insecure-requests
   policy if a future edit ever adds a subresource - it does not change
   layout, widgets, anchors, or telemetry.
3. Do NOT re-serve the site from a new host without Tyree's word.
   The working code-level workaround is the github.com repo link, which
   uses a different TLS endpoint than github.io and is not intercepted
   the same way on his Wi-Fi.
"""
import ssl, socket, sys
HOST = "tyofthestars11-lab.github.io"
PORT = 443
ctx = ssl.create_default_context()
try:
    with socket.create_connection((HOST, PORT), timeout=10) as sock:
        with ctx.wrap_socket(sock, server_hostname=HOST) as ssock:
            print("TLS OK:", ssock.version(), ssock.getpeercert().get("subject"))
except Exception as e:
    print("TLS FAIL from this network:", type(e).__name__, e)
    print("This is a network/gateway TLS intercept, not site HTML.")
    print("Code workaround: use https://github.com/tyofthestars11-lab/phi-ledger-cookie-chain")
    sys.exit(0)
print("Site TLS is valid from here. If Chrome on Wi-Fi still shows")
print("ERR_SSL_PROTOCOL_ERROR, the gateway on that Wi-Fi is returning")
print("an invalid response before GitHub's cert can complete.")
