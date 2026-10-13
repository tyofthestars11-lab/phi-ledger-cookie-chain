#!/usr/bin/env python3
"""Regression tests for the fails found 2026-10-12. Stdlib only.

Run:  python -m unittest test_phi_ledger_fails -v
"""
import json
import os
import re
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))


def read(name):
    with open(os.path.join(HERE, name), encoding="utf-8") as f:
        return f.read()


def snapshot():
    with open(os.path.join(HERE, "ledger-snapshot.json"), encoding="utf-8") as f:
        return json.load(f)


class TestPageMatchesLedger(unittest.TestCase):
    def test_search_placeholder_is_not_stale(self):
        html = read("index.html")
        self.assertNotIn("428 entries", html)

    def test_favicon_present(self):
        self.assertIn('rel="icon"', read("index.html"))

    def test_one_app_version_everywhere(self):
        html = read("index.html")
        footer = re.search(r"app v(\d+)", html).group(1)
        script = re.search(r"app\.js\?v=(\d+)", html).group(1)
        self.assertEqual(footer, script)

    def test_transaction_schema_matches_snapshot(self):
        app = read("app.js")
        snap = snapshot()
        self.assertIn(snap["snapshot_sha256"], app)
        self.assertIn("sealCount: %d" % snap["seal_count"], app)
        self.assertIn("entryCount: %d" % snap["entry_count"], app)

    def test_snapshot_hash_and_counts(self):
        import hash_snapshot
        snap = snapshot()
        self.assertEqual(snap["snapshot_sha256"], hash_snapshot.compute())
        self.assertEqual(snap["seal_count"], len(snap["seals"]))
        self.assertEqual(snap["entry_count"], len(snap["entries"]))


class TestPublishGuards(unittest.TestCase):
    def test_duplicate_seal_rejected(self):
        import publish_seal
        snap = snapshot()
        with self.assertRaises(ValueError):
            publish_seal.validate_new_seal(snap, snap["seals"][0])

    def test_blank_entry_rejected(self):
        import publish_seal
        with self.assertRaises(ValueError):
            publish_seal.validate_entry({"name": "", "value": 10})
        with self.assertRaises(ValueError):
            publish_seal.validate_entry({"value": 10})

    def test_good_entry_accepted(self):
        import publish_seal
        publish_seal.validate_entry({"name": "x", "value": 10})


class TestGridBuilder(unittest.TestCase):
    def test_grid_path_lives_beside_the_script(self):
        import build_phi_spiral_grid as b
        self.assertEqual(os.path.dirname(os.path.abspath(b.GRID_PATH)), HERE)
        self.assertEqual(os.path.basename(b.GRID_PATH), "phi_spiral_grid.json")


if __name__ == "__main__":
    unittest.main()
