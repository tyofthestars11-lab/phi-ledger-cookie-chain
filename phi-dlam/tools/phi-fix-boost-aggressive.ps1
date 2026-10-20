# PHI FIX — BOOST MODE: AGGRESSIVE — phi^2 = phi + 1
# The hidden Windows setting, unhidden and set: processor performance boost mode
# 0=off 1=on 2=AGGRESSIVE. Plus energy preference at 0 = maximum performance bias.
$ErrorActionPreference = 'SilentlyContinue'
$SUB = '54533251-82be-4824-96c1-47b60b740d00'
$BOOST = 'be337238-0d82-4146-a960-4f3749d470c7'
$EPP = '36687f9e-e3fa-4bbf-bbdb-74f37c3ec2de'
powercfg -attributes $SUB $BOOST -ATTRIB_HIDE
powercfg -attributes $SUB $EPP -ATTRIB_HIDE
"BEFORE:"; powercfg /query scheme_current $SUB $BOOST | Select-String 'Current'
powercfg /setacvalueindex scheme_current $SUB $BOOST 2
powercfg /setdcvalueindex scheme_current $SUB $BOOST 2
powercfg /setacvalueindex scheme_current $SUB $EPP 0
powercfg /setdcvalueindex scheme_current $SUB $EPP 0
powercfg /setactive scheme_current
"AFTER (boost index 2 = AGGRESSIVE, EPP 0 = max performance):"
powercfg /query scheme_current $SUB $BOOST | Select-String 'Current'
powercfg /query scheme_current $SUB $EPP | Select-String 'Current'
"=== BOOST MODE: AGGRESSIVE. The PC runs at the speed of intent. ==="
