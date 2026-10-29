# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 15:06:28 UTC

## STEP 1
```
=== JOB 565 - TERMINAL ATTACH AND HUNT WATCH READ (Ground: Job 562 showed the attach function and hunt functions exist but did not print the launcher redirect body or the hunt watch stop reason, so this job prints the attach function body and the hunt watch body from the terminal source, no patch, no relaunch. Every variable carries the p565 prefix.) ===
SOURCE LINES 1147
LAUNCHER LINE private static readonly string SystemSeatList = "explorer|sihost|textinputhost|shellexperiencehost|startmenuexperiencehost|searchhost|phiterminal|runtimebroker|applicationframehost|systemsettings|unrealeditor|cp2077launcher";
LAUNCHER LINE if (attached != null && attached.ProcessName.EndsWith("Launcher")) {
LAUNCHER LINE if (p547p.ProcessName.EndsWith("Launcher")) { continue; }
LAUNCHER LINE else { Say("LAUNCHER ONLY - the real game process was not found, powers stay on the launcher."); }
ATTACH INDEX 478
ATTACH BODY 478 private void AttachForeground()
ATTACH BODY 479 {
ATTACH BODY 480 IntPtr fg = IntPtr.Zero;
ATTACH BODY 481 EnumWindows((h, lp) =>
ATTACH BODY 482 {
ATTACH BODY 483 if (h == this.Handle) return true;
ATTACH BODY 484 if (!IsWindowVisible(h)) return true;
ATTACH BODY 485 uint wpid;
ATTACH BODY 486 GetWindowThreadProcessId(h, out wpid);
ATTACH BODY 487 if (wpid == 0) return true;
ATTACH BODY 488 try
ATTACH BODY 489 {
ATTACH BODY 490 Process wp = Process.GetProcessById((int)wpid);
ATTACH BODY 491 if (IsSystemSeat(wp.ProcessName)) return true;
ATTACH BODY 492 fg = h;
ATTACH BODY 493 return false;
ATTACH BODY 494 }
ATTACH BODY 495 catch { return true; }
ATTACH BODY 496 }, IntPtr.Zero);
ATTACH BODY 497 if (fg == IntPtr.Zero) { Say("no game window on top - open your game, then attach"); return; }
ATTACH BODY 498 uint fpid;
ATTACH BODY 499 GetWindowThreadProcessId(fg, out fpid);
ATTACH BODY 500 try { attached = Process.GetProcessById((int)fpid); SetAttached(); }
ATTACH BODY 501 catch (Exception ex) { Say("attach read an exception: " + ex.Message); }
ATTACH BODY 502 }
ATTACH BODY 503 private void SetAttached()
ATTACH BODY 504 {
ATTACH BODY 505 statusLine.Text = "ATTACHED: " + attached.ProcessName + " pid=" + attached.Id + (IsOnlineSeat(attached.ProcessName) ? "  (online game - powers rest here)" : "  (your powers work here)");
ATTACH BODY 506 if (attached != null && attached.ProcessName.EndsWith("Launcher")) {
ATTACH BODY 507 try {
ATTACH BODY 508 string p547dir = "";
ATTACH BODY 509 try { string p547f = attached.MainModule.FileName; int p547s = p547f.LastIndexOf((char)92); if (p547s > 0) { p547dir = p547f.Substring(0, p547s); } } catch {}
ATTACH BODY 510 Process p547game = null;
ATTACH BODY 511 foreach (Process p547p in Process.GetProcesses()) {
ATTACH BODY 512 try {
ATTACH BODY 513 if (p547p.Id == attached.Id) { continue; }
ATTACH BODY 514 if (p547p.ProcessName.EndsWith("Launcher")) { continue; }
ATTACH BODY 515 string p547pp = p547p.MainModule.FileName;
ATTACH BODY 516 if (p547dir != "" && p547pp.StartsWith(p547dir)) { p547game = p547p; break; }
ATTACH BODY 517 } catch {}
ATTACH BODY 518 }
ATTACH BODY 519 if (p547game != null) { attached = p547game; }
ATTACH BODY 520 else { Say("LAUNCHER ONLY - the real game process was not found, powers stay on the launcher."); }
ATTACH BODY 521 } catch {}
ATTACH BODY 522 }
ATTACH BODY 523 Say("Attached to " + attached.ProcessName + ".");
ATTACH BODY 524 HostForm.Log("ATTACH " + attached.ProcessName + " pid=" + attached.Id);
ATTACH BODY 525 }
ATTACH BODY 526 private void Godmode()
ATTACH BODY 527 {
ATTACH BODY 528 if (attached == null) { Say("godmode needs a world - attach first"); return; }
ATTACH BODY 529 if (IsOnlineSeat(attached.ProcessName))
ATTACH BODY 530 {
ATTACH BODY 531 Say("ONLINE SEAT: the terminal admires this world from outside. godmode lives in offline worlds.");
ATTACH BODY 532 HostForm.Log("GODMODE STANDDOWN online=" + attached.ProcessName);
ATTACH BODY 533 return;
ATTACH BODY 534 }
ATTACH BODY 535 long baseAddr = 0;
ATTACH BODY 536 try { baseAddr = attached.MainModule.BaseAddress.ToInt64(); } catch { }
ATTACH BODY 537 godArmed = !godArmed;
ATTACH BODY 538 godBtn.Text = godArmed ? "GODMODE: ARMED" : "GODMODE: OFF";
ATTACH BODY 539 godBtn.BackColor = godArmed ? Color.FromArgb(90, 70, 0) : Color.FromArgb(32, 32, 32);
ATTACH BODY 540 Say("GODMODE " + (godArmed ? "ARMED" : "OFF") + " " + attached.ProcessName + " base=0x" + baseAddr.ToString("X"));
ATTACH BODY 541 Say("profile stage: attach recorded whole. the health address for this world authors from this log.");
ATTACH BODY 542 HostForm.Log("GODMODE " + (godArmed ? "ARMED" : "OFF") + " " + attached.ProcessName + " base=0x" + baseAddr.ToString("X"));
ATTACH BODY 543 }
ATTACH BODY 544 private void PhiRead()
ATTACH BODY 545 {
ATTACH BODY 546 if (attached == null) { Say("phi needs a world - attach first"); return; }
ATTACH BODY 547 double bytes = attached.WorkingSet64;
ATTACH BODY 548 double rung = Math.Log(bytes) / Math.Log(1.618033988749895);
ATTACH BODY 549 Say("PHI READ " + attached.ProcessName + " lives at rung " + rung.ToString("F4") + " - " + bytes.ToString("N0") + " bytes of living world");
ATTACH BODY 550 }
ATTACH BODY 551 private class Slot
ATTACH BODY 552 {
ATTACH BODY 553 public string Name;
ATTACH BODY 554 public System.Collections.Generic.List<Cand> Cands = new System.Collections.Generic.List<Cand>();
ATTACH BODY 555 public double Value;
ATTACH BODY 556 public bool Frozen;
ATTACH BODY 557 public System.Windows.Forms.Timer Timer;
ATTACH BODY 558 public Button Btn;
ATTACH BODY 559 }
ATTACH BODY 560 private Slot slotHealth = new Slot { Name = "HEALTH" };
ATTACH BODY 561 private Slot slotAny = new Slot { Name = "ANY NUMBER" };
ATTACH BODY 562 private byte[] PatternFor(double v, bool asFloat)
ATTACH BODY 563 {
ATTACH BODY 564 if (asFloat) return BitConverter.GetBytes((float)v);
ATTACH BODY 565 return BitConverter.GetBytes((int)v);
ATTACH BODY 566 }
ATTACH BODY 567 private void ScanFirst(Slot slot, string text)
ATTACH BODY 568 {
HUNT INDEX 733
HUNT BODY 733 RunBg(() => { ScanFirst(slot, text); try { this.BeginInvoke(new Action(StartHuntWatch)); } catch { } });
HUNT BODY 734 }
HUNT BODY 735 private void StartHuntWatch()
HUNT BODY 736 {
HUNT BODY 737 if (huntSlot == null) return;
HUNT BODY 738 if (huntSlot.Cands.Count == 0) { Say(huntSlot.Name + " hunt found nothing holding that number"); if (huntSlot.Btn != null) huntSlot.Btn.Text = "INF " + huntSlot.Name + ": OFF"; huntSlot = null; return; }
HUNT BODY 739 if (huntTimer == null)
HUNT BODY 740 {
HUNT BODY 741 huntTimer = new System.Windows.Forms.Timer();
HUNT BODY 742 huntTimer.Interval = 2500;
HUNT BODY 743 huntTimer.Tick += (s2, e2) => HuntStep();
HUNT BODY 744 }
HUNT BODY 745 huntTimer.Start();
HUNT BODY 746 }
HUNT BODY 747 private void HuntStep()
HUNT BODY 748 {
HUNT BODY 749 if (huntBusy || huntSlot == null || attached == null) return;
HUNT BODY 750 if (huntSlot.Cands.Count == 0) { huntTimer.Stop(); return; }
HUNT BODY 751 huntBusy = true;
HUNT BODY 752 var slot = huntSlot;
HUNT BODY 753 int stage = huntStage;
HUNT BODY 754 var snapIn = huntSnap;
HUNT BODY 755 RunBg(() =>
HUNT BODY 756 {
HUNT BODY 757 IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
HUNT BODY 758 if (h == IntPtr.Zero) { huntBusy = false; return; }
HUNT BODY 759 var keep = new System.Collections.Generic.List<Cand>();
HUNT BODY 760 var snap = new System.Collections.Generic.Dictionary<long, double>();
HUNT BODY 761 foreach (Cand c in slot.Cands)
HUNT BODY 762 {
HUNT BODY 763 double cur = ReadNum(h, c);
HUNT BODY 764 if (double.IsNaN(cur)) continue;
HUNT BODY 765 double was;
HUNT BODY 766 bool had = snapIn.TryGetValue(c.Addr, out was);
HUNT BODY 767 if (stage == 0) { snap[c.Addr] = cur; keep.Add(c); }
HUNT BODY 768 else if (stage == 1) { if (had && Math.Abs(cur - was) > 0.001) { snap[c.Addr] = cur; keep.Add(c); } }
HUNT BODY 769 else { if (had && Math.Abs(cur - was) < 0.01) { snap[c.Addr] = cur; keep.Add(c); } }
HUNT BODY 770 }
HUNT BODY 771 CloseHandle(h);
HUNT BODY 772 try
HUNT BODY 773 {
HUNT BODY 774 this.BeginInvoke(new Action(() =>
HUNT BODY 775 {
HUNT BODY 776 huntSnap = snap; slot.Cands = keep; huntBusy = false; huntStage++;
HUNT BODY 777 HostForm.Log("HUNT " + slot.Name + " stage=" + stage + " cands=" + keep.Count);
HUNT BODY 778 if (keep.Count > 0 && keep.Count <= 64)
HUNT BODY 779 {
HUNT BODY 780 huntTimer.Stop();
HUNT BODY 781 IntPtr h2 = OpenProcess(PROCESS_ALL, false, attached.Id);
HUNT BODY 782 if (h2 != IntPtr.Zero) { double cur2 = ReadNum(h2, keep[0]); if (!double.IsNaN(cur2) && cur2 > 0) slot.Value = cur2; CloseHandle(h2); }
HUNT BODY 783 huntSlot = null;
HUNT BODY 784 if (slot.Value > 0 && !slot.Frozen) SlotToggle(slot);
HUNT BODY 785 if (slot.Frozen) Say("INF " + slot.Name + " LOCKED at " + slot.Value + " - one click, done");
HUNT BODY 786 else { if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + ": narrowed to " + keep.Count + " - type the number once more and press INF " + slot.Name + " to hold it"); }
HUNT BODY 787 }
HUNT BODY 788 else if (keep.Count == 0) { huntTimer.Stop(); huntSlot = null; if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + " hunt lost the trail - press INF " + slot.Name + " again with the number showing"); }
HUNT BODY 789 else if (huntStage > 3) { huntTimer.Stop(); huntSlot = null; if (slot.Btn != null) slot.Btn.Text = "INF " + slot.Name + ": OFF"; Say(slot.Name + ": " + keep.Count + " addresses still move together - type the NEW number in the box and press INF " + slot.Name + " once to refine by hand"); }
HUNT BODY 790 }));
HUNT BODY 791 }
HUNT BODY 792 catch { huntBusy = false; }
HUNT BODY 793 });
HUNT BODY 794 }
HUNT BODY 795 private int flyStep = 0;
HUNT BODY 796 private System.Windows.Forms.Timer flyWatch;
HUNT BODY 797 private int flyTicks = 0;
HUNT BODY 798 private bool flyBusy = false;
HUNT BODY 799 private void OneFly()
HUNT BODY 800 {
HUNT BODY 801 if (flyFrozen) { FlyToggle(); return; }
HUNT BODY 802 if (flyStep > 0)
HUNT BODY 803 {
MASTER INDEX 183
MASTER BODY 183 godBtn = MakeBtn("GODMODE ALL: OFF", (s, e) => MasterToggle());
MASTER BODY 184 btnRow.Controls.Add(godBtn);
MASTER BODY 185 btnRow.Controls.Add(MakeBtn("PHI READ", (s, e) => PhiRead()));
MASTER BODY 186 btnRow.Controls.Add(MakeBtn("HIDE (~)", (s, e) => HideSafe()));
MASTER BODY 187 var btnRow2 = new FlowLayoutPanel();
MASTER BODY 188 btnRow2.Dock = DockStyle.Top;
MASTER BODY 189 btnRow2.Height = 44;
MASTER BODY 190 btnRow2.BackColor = Color.Black;
MASTER BODY 191 slotHealth.Btn = MakeBtn("INF HEALTH: OFF", (s, e) => OnePower(slotHealth));
MASTER BODY 192 btnRow2.Controls.Add(slotHealth.Btn);
MASTER BODY 193 slotAny.Btn = MakeBtn("INF AMMO / ANY NUMBER: OFF", (s, e) => OnePower(slotAny));
MASTER BODY 194 btnRow2.Controls.Add(slotAny.Btn);
MASTER BODY 195 var btnRow3 = new FlowLayoutPanel();
MASTER BODY 196 btnRow3.Dock = DockStyle.Top;
MASTER BODY 197 btnRow3.Height = 44;
MASTER BODY 198 btnRow3.BackColor = Color.Black;
MASTER BODY 199 flyBtn = MakeBtn("FLY: OFF", (s, e) => OneFly());
MASTER BODY 200 btnRow3.Controls.Add(flyBtn);
MASTER BODY 201 outBox = new RichTextBox();
MASTER BODY 202 outBox.Dock = DockStyle.Fill;
MASTER BODY 203 outBox.BackColor = Color.Black;
MASTER BODY 204 outBox.ForeColor = Color.Gold;
MASTER BODY 205 outBox.Font = new Font("Consolas", 11);
MASTER BODY 206 outBox.ReadOnly = true;
MASTER BODY 207 outBox.BorderStyle = BorderStyle.None;
MASTER BODY 208 inBox = new TextBox();
MASTER BODY 209 inBox.Dock = DockStyle.Bottom;
MASTER BODY 210 inBox.BackColor = Color.FromArgb(24, 24, 24);
MASTER BODY 211 inBox.ForeColor = Color.Gold;
MASTER BODY 212 inBox.Font = new Font("Consolas", 12, FontStyle.Bold);
MASTER BODY 213 inBox.BorderStyle = BorderStyle.FixedSingle;
MASTER BODY 214 inBox.KeyDown += OnKey;
MASTER BODY 215 this.Controls.Add(btnRow3);
MASTER BODY 216 this.Controls.Add(btnRow2);
MASTER BODY 217 this.Controls.Add(btnRow);
MASTER BODY 218 this.Controls.Add(lib);
MASTER BODY 219 this.Controls.Add(statusLine);
MASTER BODY 220 this.Controls.Add(head);
MASTER BODY 221 this.Controls.Add(inBox);
MASTER BODY 222 this.Controls.Add(outBox);
MASTER BODY 223 this.Shown += (s, e) => { this.Activate(); inBox.Focus(); };
PHI P565 VERDICT: TERMINAL ATTACH AND HUNT WATCH READ ABOVE
JOB 565 DONE

```
