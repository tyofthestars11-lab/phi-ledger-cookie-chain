# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 03:35:18 UTC

## STEP 1
```
=== JOB 551 - PRINT THE BULK NARROW (Ground: job 550 printed the fly mark pattern, a bounded band scan capped at 400000, narrowed by play. The value narrow step reads one address at a time, so it cannot chew a mark that big, and the fly bulk narrow body is the last missing piece before the value hunt mirror is written. This job prints that bulk narrow body plus the value read and the hunt watch wiring. No patch rides this job, no rebuild, no relaunch. No game relaunch rides this job. Every variable carries the p551 prefix.) ===
SOURCE LINES=1080
REGION 869         private void FlyRefineCore()
REGION 870         {
REGION 871             if (attached == null || flyCands.Count == 0) return;
REGION 872             IntPtr h = OpenProcess(PROCESS_ALL, false, attached.Id);
REGION 873             if (h == IntPtr.Zero) return;
REGION 874             var keep = new System.Collections.Generic.List<long>();
REGION 875             foreach (long za in flyCands)
REGION 876             {
REGION 877                 float now = ReadF(h, za);
REGION 878                 if (float.IsNaN(now)) continue;
REGION 879                 float was;
REGION 880                 if (!flyBase.TryGetValue(za, out was)) continue;
REGION 881                 float d = now - was;
REGION 882                 if (d > 0.05f && d < 1000f)
REGION 883                 {
REGION 884                     float xNow = ReadF(h, za - 8);
REGION 885                     float yNow = ReadF(h, za - 4);
REGION 886                     if (!float.IsNaN(xNow) && !float.IsNaN(yNow)) { keep.Add(za); flyBase[za] = now; }
REGION 887                 }
REGION 888             }
REGION 889             CloseHandle(h);
REGION 890             flyCands = keep;
REGION 891             HostForm.Log("FLYHUNT cands=" + keep.Count);
REGION 892         }
REGION 701         private double ReadNum(IntPtr h, Cand c)
REGION 702         {
REGION 703             byte[] b = new byte[4];
REGION 704             int r;
REGION 705             if (ReadProcessMemory(h, (IntPtr)c.Addr, b, 4, out r) && r == 4) return c.IsFloat ? (double)BitConverter.ToSingle(b, 0) : (double)BitConverter.ToInt32(b, 0);
REGION 706             return double.NaN;
REGION 707         }
REGION 736         private void StartHuntWatch()
REGION 737         {
REGION 738             if (huntSlot == null) return;
REGION 739             if (huntSlot.Cands.Count == 0) { Say(huntSlot.Name + " hunt found nothing holding that number"); if (huntSlot.Btn != null) huntSlot.Btn.Text = "INF " + huntSlot.Name + ": OFF"; huntSlot = null; return; }
REGION 740             if (huntTimer == null)
REGION 741             {
REGION 742                 huntTimer = new System.Windows.Forms.Timer();
REGION 743                 huntTimer.Interval = 2500;
REGION 744                 huntTimer.Tick += (s2, e2) => HuntStep();
REGION 745             }
REGION 746             huntTimer.Start();
REGION 747         }
PRINTED - BULK NARROW BODIES ABOVE
VERDICT PRINTED
PHI P551 VERDICT: BULK NARROW BODIES ABOVE
JOB 551 DONE

```
