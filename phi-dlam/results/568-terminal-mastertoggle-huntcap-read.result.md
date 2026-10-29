# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 15:18:32 UTC

## STEP 1
```
=== JOB 568 - TERMINAL MASTERTOGGLE AND HUNTCAP READ (Ground: Job 565 printed the hunt watch stop at stage over 3 and the attach redirect body but not the MasterToggle function body, so this job prints the MasterToggle function definition and the hunt cap lines, no patch, no relaunch. Every variable carries the p568 prefix.) ===
SOURCE LINES 1147
MASTER INDEX 956
MASTER BODY 956 private void MasterToggle()
MASTER BODY 957 {
MASTER BODY 958 bool anyOn = slotHealth.Frozen || slotAny.Frozen || flyFrozen;
MASTER BODY 959 if (anyOn)
MASTER BODY 960 {
MASTER BODY 961 if (slotHealth.Frozen) SlotToggle(slotHealth);
MASTER BODY 962 if (slotAny.Frozen) SlotToggle(slotAny);
MASTER BODY 963 if (flyFrozen) FlyToggle();
MASTER BODY 964 godBtn.Text = "GODMODE ALL: OFF";
MASTER BODY 965 godBtn.BackColor = Color.FromArgb(32, 32, 32);
MASTER BODY 966 Say("GODMODE ALL OFF - every power rests");
MASTER BODY 967 return;
MASTER BODY 968 }
MASTER BODY 969 int armed = 0;
MASTER BODY 970 if (slotHealth.Cands.Count > 0 && slotHealth.Cands.Count <= 64) { if (!slotHealth.Frozen) SlotToggle(slotHealth); armed++; }
MASTER BODY 971 if (slotAny.Cands.Count > 0 && slotAny.Cands.Count <= 64) { if (!slotAny.Frozen) SlotToggle(slotAny); armed++; }
MASTER BODY 972 if (flyCands.Count > 0) { if (!flyFrozen) FlyToggle(); armed++; }
MASTER BODY 973 if (!(slotHealth.Cands.Count > 0 && slotHealth.Cands.Count <= 64) && !slotHealth.Frozen) OneValue(slotHealth);
MASTER BODY 974 if (!(slotAny.Cands.Count > 0 && slotAny.Cands.Count <= 64) && !slotAny.Frozen) OneValue(slotAny);
MASTER BODY 975 if (!(flyCands.Count > 0) && !flyFrozen) OneFly();
MASTER BODY 976 if (armed == 0) { Say("GODMODE: one click - the hunts run for you now"); return; }
MASTER BODY 977 godBtn.Text = "GODMODE ALL: ON";
MASTER BODY 978 godBtn.BackColor = Color.FromArgb(90, 70, 0);
MASTER BODY 979 Say("GODMODE ALL ON - " + armed + " powers hold at once");
MASTER BODY 980 HostForm.Log("GODMODE ALL ON armed=" + armed);
MASTER BODY 981 }
MASTER BODY 982 private System.Collections.Generic.List<long> flyCands = new System.Collections.Generic.List<long>();
MASTER BODY 983 private System.Collections.Generic.Dictionary<long, float> flyBase = new System.Collections.Generic.Dictionary<long, float>();
MASTER BODY 984 private bool flyFrozen = false;
MASTER BODY 985 private System.Windows.Forms.Timer flyTimer;
MASTER BODY 986 private Button flyBtn;
MASTER BODY 987 private float ReadF(IntPtr h, long a)
MASTER BODY 988 {
MASTER BODY 989 byte[] b = new byte[4];
MASTER BODY 990 int r;
MASTER BODY 991 if (ReadProcessMemory(h, (IntPtr)a, b, 4, out r) && r == 4) return BitConverter.ToSingle(b, 0);
MASTER BODY 992 return float.NaN;
MASTER BODY 993 }
MASTER BODY 994 private void FlyMark()
MASTER BODY 995 {
MASTER BODY 996 if (attached == null) { Say("No game yet - open your game and I attach myself to it."); return; }
MASTER BODY 997 if (IsOnlineSeat(attached.ProcessName)) { Say("ONLINE SEAT: the terminal stands outside this world."); return; }
MASTER BODY 998 flyCands.Clear();
MASTER BODY 999 flyBase.Clear();
MASTER BODY 1000 IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
MASTER BODY 1001 if (h == IntPtr.Zero) { Say("the door did not open"); return; }
MASTER BODY 1002 long addr = 0;
MASTER BODY 1003 var mbi = new MBI();
MASTER BODY 1004 while (addr < 0x7FFFFFFFFFFFL)
MASTER BODY 1005 {
MASTER BODY 1006 int q = VirtualQueryEx(h, (IntPtr)addr, out mbi, Marshal.SizeOf(typeof(MBI)));
MASTER BODY 1007 if (q == 0) break;
MASTER BODY 1008 long regionSize = mbi.RegionSize.ToInt64();
MASTER BODY 1009 if (regionSize <= 0) break;
MASTER BODY 1010 bool readable = mbi.State == 0x1000 && (mbi.Protect & 0x100) == 0 && (mbi.Protect & 0x01) == 0;
MASTER BODY 1011 if (readable)
MASTER BODY 1012 {
MASTER BODY 1013 long baseA = mbi.BaseAddress.ToInt64();
MASTER BODY 1014 int chunk = 1024 * 1024;
MASTER BODY 1015 for (long off = 0; off + 16 <= regionSize; off += chunk)
MASTER BODY 1016 {
MASTER BODY 1017 int want = (int)Math.Min(chunk, regionSize - off);
MASTER BODY 1018 byte[] buf = new byte[want];
MASTER BODY 1019 int read;
MASTER BODY 1020 if (ReadProcessMemory(h, (IntPtr)(baseA + off), buf, want, out read) && read >= 16)
MASTER BODY 1021 {
MASTER BODY 1022 for (int i = 0; i + 12 <= read; i += 4)
MASTER BODY 1023 {
MASTER BODY 1024 float z = BitConverter.ToSingle(buf, i + 8);
MASTER BODY 1025 if (float.IsNaN(z) || float.IsInfinity(z)) continue;
MASTER BODY 1026 if (z > -5000f && z < 5000f && Math.Abs(z) > 0.01f)
MASTER BODY 1027 {
MASTER BODY 1028 long za = baseA + off + i + 8;
MASTER BODY 1029 flyCands.Add(za);
MASTER BODY 1030 flyBase[za] = z;
MASTER BODY 1031 }
MASTER BODY 1032 if (flyCands.Count > 400000) break;
MASTER BODY 1033 }
MASTER BODY 1034 }
MASTER BODY 1035 if (flyCands.Count > 400000) break;
MASTER BODY 1036 }
HUNT LINE private int huntStage = 0;
HUNT LINE huntSlot = slot; huntStage = 0; huntSnap.Clear();
HUNT LINE int stage = huntStage;
HUNT LINE huntSnap = snap; slot.Cands = keep; huntBusy = false; huntStage++;
HUNT LINE else if (huntStage > 3) { huntTimer.Stop(); huntSlot = null; if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + ": " + keep.Count + " addresses still move together - type the NEW number in the box and press INF " + slot.Name + " once to refine by hand"); }
HUNT LINE huntSlot = slot; huntStage = 0; huntSnap.Clear();
PHI P568 VERDICT: TERMINAL MASTERTOGGLE AND HUNTCAP READ ABOVE
JOB 568 DONE

```
