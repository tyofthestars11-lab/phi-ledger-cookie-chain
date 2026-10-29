# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 03:17:23 UTC

## STEP 1
```
=== JOB 550 - PRINT THE NO NUMBER HUNT PATTERN (Ground: job 548 held the all on patch because the value hunt start needs a typed number, while the fly hunt starts with no number at all. This job prints the fly hunt pattern bodies plus the refine and pattern bodies, so the value hunt mirror is written against complete code, not a guess. No patch rides this job, no rebuild, no relaunch. No game relaunch rides this job. Every variable carries the p550 prefix.) ===
SOURCE LINES=1080
REGION 928         private void FlyMark()
REGION 929         {
REGION 930             if (attached == null) { Say("No game yet - open your game and I attach myself to it."); return; }
REGION 931             if (IsOnlineSeat(attached.ProcessName)) { Say("ONLINE SEAT: the terminal stands outside this world."); return; }
REGION 932             flyCands.Clear();
REGION 933             flyBase.Clear();
REGION 934             IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 935             if (h == IntPtr.Zero) { Say("the door did not open"); return; }
REGION 936             long addr = 0;
REGION 937             var mbi = new MBI();
REGION 938             while (addr < 0x7FFFFFFFFFFFL)
REGION 939             {
REGION 940                 int q = VirtualQueryEx(h, (IntPtr)addr, out mbi, Marshal.SizeOf(typeof(MBI)));
REGION 941                 if (q == 0) break;
REGION 942                 long regionSize = mbi.RegionSize.ToInt64();
REGION 943                 if (regionSize <= 0) break;
REGION 944                 bool readable = mbi.State == 0x1000 && (mbi.Protect & 0x100) == 0 && (mbi.Protect & 0x01) == 0;
REGION 945                 if (readable)
REGION 946                 {
REGION 947                     long baseA = mbi.BaseAddress.ToInt64();
REGION 948                     int chunk = 1024 * 1024;
REGION 949                     for (long off = 0; off + 16 <= regionSize; off += chunk)
REGION 950                     {
REGION 951                         int want = (int)Math.Min(chunk, regionSize - off);
REGION 952                         byte[] buf = new byte[want];
REGION 953                         int read;
REGION 954                         if (ReadProcessMemory(h, (IntPtr)(baseA + off), buf, want, out read) && read >= 16)
REGION 955                         {
REGION 956                             for (int i = 0; i + 12 <= read; i += 4)
REGION 957                             {
REGION 958                                 float z = BitConverter.ToSingle(buf, i + 8);
REGION 959                                 if (float.IsNaN(z) || float.IsInfinity(z)) continue;
REGION 960                                 if (z > -5000f && z < 5000f && Math.Abs(z) > 0.01f)
REGION 961                                 {
REGION 962                                     long za = baseA + off + i + 8;
REGION 963                                     flyCands.Add(za);
REGION 964                                     flyBase[za] = z;
REGION 965                                 }
REGION 966                                 if (flyCands.Count > 400000) break;
REGION 967                             }
REGION 968                         }
REGION 969                         if (flyCands.Count > 400000) break;
REGION 970                     }
REGION 971                 }
REGION 972                 addr = mbi.BaseAddress.ToInt64() + regionSize;
REGION 973                 if (flyCands.Count > 400000) break;
REGION 974             }
REGION 975             CloseHandle(h);
REGION 976             Say("Looking for your height - stand still a moment while I look.");
REGION 977             Say("Now jump and climb - I am watching your height rise.");
REGION 978             HostForm.Log("FLYMARK cands=" + flyCands.Count);
REGION 979         }
REGION 748         private void HuntStep()
REGION 749         {
REGION 750             if (huntBusy || huntSlot == null || attached == null) return;
REGION 751             if (huntSlot.Cands.Count == 0) { huntTimer.Stop(); return; }
REGION 752             huntBusy = true;
REGION 753             var slot = huntSlot;
REGION 754             int stage = huntStage;
REGION 755             var snapIn = huntSnap;
REGION 756             RunBg(() =>
REGION 757             {
REGION 758                 IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 759                 if (h == IntPtr.Zero) { huntBusy = false; return; }
REGION 760                 var keep = new System.Collections.Generic.List<Cand>();
REGION 761                 var snap = new System.Collections.Generic.Dictionary<long, double>();
REGION 762                 foreach (Cand c in slot.Cands)
REGION 763                 {
REGION 764                     double cur = ReadNum(h, c);
REGION 765                     if (double.IsNaN(cur)) continue;
REGION 766                     double was;
REGION 767                     bool had = snapIn.TryGetValue(c.Addr, out was);
REGION 768                     if (stage == 0) { snap[c.Addr] = cur; keep.Add(c); }
REGION 769                     else if (stage == 1) { if (had && Math.Abs(cur - was) > 0.001) { snap[c.Addr] = cur; keep.Add(c); } }
REGION 770                     else { if (had && Math.Abs(cur - was) < 0.01) { snap[c.Addr] = cur; keep.Add(c); } }
REGION 771                 }
REGION 772                 CloseHandle(h);
REGION 773                 try
REGION 774                 {
REGION 775                     this.BeginInvoke(new Action(() =>
REGION 776                     {
REGION 777                         huntSnap = snap; slot.Cands = keep; huntBusy = false; huntStage++;
REGION 778                         HostForm.Log("HUNT " + slot.Name + " stage=" + stage + " cands=" + keep.Count);
REGION 779                         if (keep.Count > 0 && keep.Count <= 64)
REGION 780                         {
REGION 781                             huntTimer.Stop();
REGION 782                             IntPtr h2 = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 783                             if (h2 != IntPtr.Zero) { double cur2 = ReadNum(h2, keep[0]); if (!double.IsNaN(cur2) && cur2 > 0) slot.Value = cur2; CloseHandle(h2); }
REGION 784                             huntSlot = null;
REGION 785                             if (slot.Value > 0 && !slot.Frozen) SlotToggle(slot);
REGION 786                             if (slot.Frozen) Say("INF " + slot.Name + " LOCKED at " + slot.Value + " - one click, done");
REGION 787                             else { if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + ": narrowed to " + keep.Count + " - type the number once more and press INF " + slot.Name + " to hold it"); }
REGION 788                         }
REGION 789                         else if (keep.Count == 0) { huntTimer.Stop(); huntSlot = null; if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + " hunt lost the trail - press INF " + slot.Name + " again with the number showing"); }
REGION 790                         else if (huntStage > 3) { huntTimer.Stop(); huntSlot = null; if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + ": " + keep.Count + " addresses still move together - type the NEW number in the box and press INF " + slot.Name + " once to refine by hand"); }
REGION 791                     }));
REGION 792                 }
REGION 793                 catch { huntBusy = false; }
REGION 794             });
REGION 795         }
REGION 836         private void FlyWatchStep()
REGION 837         {
REGION 838             flyTicks++;
REGION 839             if (flyBusy) return;
REGION 840             if (attached == null || flyCands.Count == 0) { if (flyWatch != null) flyWatch.Stop(); return; }
REGION 841             flyBusy = true;
REGION 842             RunBg(() =>
REGION 843             {
REGION 844                 FlyRefineCore();
REGION 845                 try
REGION 846                 {
REGION 847                     this.BeginInvoke(new Action(() =>
REGION 848                     {
REGION 849                         flyBusy = false;
REGION 850                         if (flyCands.Count > 0 && flyCands.Count <= 64)
REGION 851                         {
REGION 852                             if (flyWatch != null) flyWatch.Stop();
REGION 853                             flyStep = 0;
REGION 854                             if (!flyFrozen) FlyToggle();
REGION 855                             Say("FLY LOCKED on " + flyCands.Count + " heights - you rise. Press FLY to land.");
REGION 856                         }
REGION 857                         else if (flyTicks > 14)
REGION 858                         {
REGION 859                             if (flyWatch != null) flyWatch.Stop();
REGION 860                             flyStep = 0;
REGION 861                             if (flyBtn != null) flyBtn.Text = "FLY: OFF";
REGION 862                             Say("FLY: " + flyCands.Count + " heights still move together - press FLY once more and jump higher");
REGION 863                         }
REGION 864                     }));
REGION 865                 }
REGION 866                 catch { flyBusy = false; }
REGION 867             });
REGION 868         }
REGION 625         private void ScanRefine(Slot slot, string text)
REGION 626         {
REGION 627             if (attached == null || slot.Cands.Count == 0) { Say(slot.Name + ": no scan stands - FIND first"); return; }
REGION 628             double v;
REGION 629             if (!double.TryParse(text, out v)) { Say("type the NEW number in the box below first"); return; }
REGION 630             IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 631             if (h == IntPtr.Zero) { Say("the door did not open"); return; }
REGION 632             var keep = new System.Collections.Generic.List<Cand>();
REGION 633             byte[] buf = new byte[4];
REGION 634             foreach (Cand c in slot.Cands)
REGION 635             {
REGION 636                 int read;
REGION 637                 if (ReadProcessMemory(h, (IntPtr)c.Addr, buf, 4, out read) && read == 4)
REGION 638                 {
REGION 639                     double cur = c.IsFloat ? (double)BitConverter.ToSingle(buf, 0) : (double)BitConverter.ToInt32(buf, 0);
REGION 640                     if (Math.Abs(cur - v) < 0.01) keep.Add(c);
REGION 641                 }
REGION 642             }
REGION 643             CloseHandle(h);
REGION 644             slot.Cands = keep;
REGION 645             slot.Value = v;
REGION 646             Say(slot.Name + ": " + slot.Cands.Count + " places still hold " + v + ".");
REGION 647             if (slot.Cands.Count <= 16 && slot.Cands.Count > 0) Say(slot.Name + " is pinned down - press INF " + slot.Name + " and it holds.");
REGION 648             else if (slot.Cands.Count > 16) Say("Still a few places - let the number change once more, then press the button again.");
REGION 649             HostForm.Log("REFINE " + slot.Name + " v=" + v + " cands=" + slot.Cands.Count);
REGION 650         }
REGION 563         private byte[] PatternFor(double v, bool asFloat)
REGION 564         {
REGION 565             if (asFloat) return BitConverter.GetBytes((float)v);
REGION 566             return BitConverter.GetBytes((int)v);
REGION 567         }
PRINTED - HUNT PATTERN BODIES ABOVE
VERDICT PRINTED
PHI P550 VERDICT: HUNT PATTERN BODIES ABOVE
JOB 550 DONE

```
