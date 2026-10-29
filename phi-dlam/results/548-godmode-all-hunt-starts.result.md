# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 03:12:24 UTC

## STEP 1
```
=== JOB 548 - GODMODE ALL STARTS EVERY HUNT BY ITSELF (Ground: job 545 printed the godmode body, and its armed count only switches on powers already narrowed, so a press with only fly ready never starts the health or ammo hunts. This job prints the hunt method bodies, and if the hunt start needs no typed number it seats hunt starts for every unarmed power before the armed check and trims the fallback so no hunt starts twice, then rebuilds plus relaunches only on a clean build with the live files untouched on any miss. No game relaunch rides this job. Every variable carries the p548 prefix.) ===
SOURCE LINES=1080
REGION 708         private void OnePower(Slot slot)
REGION 709         {
REGION 710             if (slot.Frozen) { SlotToggle(slot); return; }
REGION 711             if (huntTimer != null && huntSlot == slot)
REGION 712             {
REGION 713                 huntTimer.Stop(); huntSlot = null;
REGION 714                 if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF";
REGION 715                 Say(slot.Name + " hunt rested - press again to hunt fresh");
REGION 716                 return;
REGION 717             }
REGION 718             if (attached == null) { Say("No game yet - open your game and I attach myself to it."); return; }
REGION 719             if (IsOnlineSeat(attached.ProcessName)) { Say("ONLINE SEAT: the terminal stands outside this world."); return; }
REGION 720             if (slot.Cands.Count > 0 && slot.Cands.Count <= 64 && slot.Value > 0) { SlotToggle(slot); return; }
REGION 721             string text = inBox.Text.Trim();
REGION 722             double nv;
REGION 723             if (slot.Cands.Count > 0 && double.TryParse(text, out nv) && Math.Abs(nv - slot.Value) > 0.001)
REGION 724             {
REGION 725                 RunBg(() => ScanRefine(slot, text));
REGION 726                 Say(slot.Name + ": refining to " + text + " - when the count is small, press INF " + slot.Name + " once more and it holds");
REGION 727                 return;
REGION 728             }
REGION 729             double v;
REGION 730             if (!double.TryParse(text, out v)) { Say("Type your number from the game screen in the box below, then press INF " + slot.Name + " once."); return; }
REGION 731             huntSlot = slot; huntStage = 0; huntSnap.Clear();
REGION 732             if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": HUNTING";
REGION 733             Say("INF " + slot.Name + ": one click taken - hunting " + v + " for you. Play on: let the number change and the terminal follows it.");
REGION 734             RunBg(() => { ScanFirst(slot, text); try { this.BeginInvoke(new Action(StartHuntWatch)); } catch { } });
REGION 735         }
REGION 800         private void OneFly()
REGION 801         {
REGION 802             if (flyFrozen) { FlyToggle(); return; }
REGION 803             if (flyStep > 0)
REGION 804             {
REGION 805                 flyStep = 0;
REGION 806                 if (flyWatch != null) flyWatch.Stop();
REGION 807                 if (flyBtn != null) flyBtn.Text = "FLY: OFF";
REGION 808                 Say("FLY rested");
REGION 809                 return;
REGION 810             }
REGION 811             if (attached == null) { Say("No game yet - open your game and I attach myself to it."); return; }
REGION 812             if (IsOnlineSeat(attached.ProcessName)) { Say("ONLINE SEAT: the terminal stands outside this world."); return; }
REGION 813             flyStep = 1;
REGION 814             if (flyBtn != null) flyBtn.Text = "FLY: HUNTING";
REGION 815             Say("FLY: one click taken - hunting your height. Now JUMP and climb for a few seconds, DCUO style: hold jump and rise.");
REGION 816             RunBg(() =>
REGION 817             {
REGION 818                 FlyMark();
REGION 819                 try
REGION 820                 {
REGION 821                     this.BeginInvoke(new Action(() =>
REGION 822                     {
REGION 823                         flyTicks = 0;
REGION 824                         if (flyWatch == null)
REGION 825                         {
REGION 826                             flyWatch = new System.Windows.Forms.Timer();
REGION 827                             flyWatch.Interval = 700;
REGION 828                             flyWatch.Tick += (s2, e2) => FlyWatchStep();
REGION 829                         }
REGION 830                         flyWatch.Start();
REGION 831                     }));
REGION 832                 }
REGION 833                 catch { }
REGION 834             });
REGION 835         }
REGION 651         private void SlotToggle(Slot slot)
REGION 652         {
REGION 653             if (slot.Frozen)
REGION 654             {
REGION 655                 if (slot.Timer != null) slot.Timer.Stop();
REGION 656                 slot.Frozen = false;
REGION 657                 if (slot.Btn != null) { slot.Btn.Text = "INF " + slot.Name + ": OFF"; slot.Btn.BackColor = Color.FromArgb(32, 32, 32); }
REGION 658                 Say(slot.Name + " released - it moves again.");
REGION 659                 HostForm.Log("FREEZE OFF " + slot.Name);
REGION 660                 return;
REGION 661             }
REGION 662             if (attached == null || slot.Cands.Count == 0) { Say(slot.Name + ": type the number from your game screen in the box below, then press this button once."); return; }
REGION 663             if (slot.Cands.Count > 64) { Say(slot.Name + ": still looking in " + slot.Cands.Count + " places - let the number change and press again."); return; }
REGION 664             if (slot.Value <= 0) { Say(slot.Name + ": value missing - REFINE once so the terminal knows the number"); return; }
REGION 665             if (slot.Timer == null)
REGION 666             {
REGION 667                 var t = new System.Windows.Forms.Timer();
REGION 668                 t.Interval = 120;
REGION 669                 var cap = slot;
REGION 670                 t.Tick += (s2, e2) => WriteSlot(cap);
REGION 671                 slot.Timer = t;
REGION 672             }
REGION 673             slot.Timer.Start();
REGION 674             slot.Frozen = true;
REGION 675             if (slot.Btn != null) { slot.Btn.Text = "INF " + slot.Name + ": ON"; slot.Btn.BackColor = Color.FromArgb(90, 70, 0); }
REGION 676             Say(slot.Name + " is locked at " + slot.Value + ". It will not move.");
REGION 677             HostForm.Log("FREEZE ON " + slot.Name + " v=" + slot.Value + " cands=" + slot.Cands.Count);
REGION 678         }
REGION 568         private void ScanFirst(Slot slot, string text)
REGION 569         {
REGION 570             if (attached == null) { Say("No game yet - open your game and I attach myself to it."); return; }
REGION 571             if (IsOnlineSeat(attached.ProcessName)) { Say("ONLINE SEAT: the terminal stands outside this world."); return; }
REGION 572             double v;
REGION 573             if (!double.TryParse(text, out v)) { Say("type the number from the game in the box below first - for health, the red HUD number"); return; }
REGION 574             slot.Cands.Clear();
REGION 575             IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 576             if (h == IntPtr.Zero) { Say("the door did not open - the game refused the attach"); return; }
REGION 577             long addr = 0;
REGION 578             long scanned = 0;
REGION 579             byte[] patF = PatternFor(v, true);
REGION 580             byte[] patI = PatternFor(v, false);
REGION 581             var mbi = new MBI();
REGION 582             var seen = new System.Collections.Generic.HashSet<long>();
REGION 583             while (addr < 0x7FFFFFFFFFFFL)
REGION 584             {
REGION 585                 int q = VirtualQueryEx(h, (IntPtr)addr, out mbi, Marshal.SizeOf(typeof(MBI)));
REGION 586                 if (q == 0) break;
REGION 587                 long regionSize = mbi.RegionSize.ToInt64();
REGION 588                 if (regionSize <= 0) break;
REGION 589                 bool readable = mbi.State == 0x1000 && (mbi.Protect & 0x100) == 0 && (mbi.Protect & 0x01) == 0;
REGION 590                 if (readable)
REGION 591                 {
REGION 592                     long baseA = mbi.BaseAddress.ToInt64();
REGION 593                     int chunk = 1024 * 1024;
REGION 594                     for (long off = 0; off < regionSize; off += chunk)
REGION 595                     {
REGION 596                         int want = (int)Math.Min(chunk, regionSize - off);
REGION 597                         byte[] buf = new byte[want];
REGION 598                         int read;
REGION 599                         if (ReadProcessMemory(h, (IntPtr)(baseA + off), buf, want, out read) && read > 4)
REGION 600                         {
REGION 601                             scanned += read;
REGION 602                             for (int i = 0; i + 4 <= read; i++)
REGION 603                             {
REGION 604                                 bool f = buf[i] == patF[0] && buf[i + 1] == patF[1] && buf[i + 2] == patF[2] && buf[i + 3] == patF[3];
REGION 605                                 bool n = !f && buf[i] == patI[0] && buf[i + 1] == patI[1] && buf[i + 2] == patI[2] && buf[i + 3] == patI[3];
REGION 606                                 if (f || n)
REGION 607                                 {
REGION 608                                     long a = baseA + off + i;
REGION 609                                     if (seen.Add(a)) slot.Cands.Add(new Cand { Addr = a, IsFloat = f });
REGION 610                                 }
REGION 611                                 if (slot.Cands.Count > 200000) break;
REGION 612                             }
REGION 613                         }
REGION 614                         if (slot.Cands.Count > 200000) break;
REGION 615                     }
REGION 616                 }
REGION 617                 addr = mbi.BaseAddress.ToInt64() + regionSize;
REGION 618                 if (slot.Cands.Count > 200000) break;
REGION 619             }
REGION 620             CloseHandle(h);
REGION 621             Say("Looking for your number " + v + " - I found it in " + slot.Cands.Count + " places. Play on and let it change; I narrow it down as you play.");
REGION 622             Say("Now let the number change in the game - get hit, heal, shoot - and I follow it.");
REGION 623             HostForm.Log("FIND " + slot.Name + " v=" + v + " cands=" + slot.Cands.Count);
REGION 624         }
MARKERS master=True armed=True onepowercall=True opbody=True
ALLON GAP - ONEPOWER NEEDS TYPED NUMBER
VERDICT ALLON GAP - ONEPOWER NEEDS TYPED NUMBER
PATCH HELD - LIVE FILES UNTOUCHED
PHI P548 VERDICT: ALLON HUNT STARTS ABOVE
JOB 548 DONE

```
