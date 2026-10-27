<!-- PHI-DIRECT -->
# JOB 071 - BLUETOOTH GAMEPAD READ (DIRECT, SHORT)

Tyree wants his Xbox controller on Bluetooth. Both games already carry
the full pad map in code; the only question is the PC side: is a pad
paired and connected over Bluetooth right now? Read only.

```powershell
"=== BLUETOOTH RADIOS / STATE ==="
Get-PnpDevice -Class Bluetooth -ErrorAction SilentlyContinue | Select-Object -First 6 | ForEach-Object { "$($_.Status) | $($_.FriendlyName)" }
"=== GAME CONTROLLERS (any transport) ==="
Get-PnpDevice -ErrorAction SilentlyContinue | Where-Object { $_.FriendlyName -match 'Xbox|Gamepad|Controller' -and $_.Class -match 'HIDClass|XboxComposite|Bluetooth' } | ForEach-Object { "$($_.Status) | $($_.Class) | $($_.FriendlyName)" }
"=== PAIRED BLUETOOTH DEVICES ==="
Get-PnpDevice -Class Bluetooth -ErrorAction SilentlyContinue | Where-Object { $_.FriendlyName -match 'Xbox|Controller' } | ForEach-Object { "$($_.Status) | $($_.FriendlyName) | $($_.InstanceId)" }
"=== HID GAME DEVICES ==="
Get-CimInstance Win32_PnPEntity -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'Xbox Wireless Controller|Game Controller|HID-compliant game controller' } | ForEach-Object { "$($_.Status) | $($_.Name)" }
"=== JOB 071 DONE ==="
```
