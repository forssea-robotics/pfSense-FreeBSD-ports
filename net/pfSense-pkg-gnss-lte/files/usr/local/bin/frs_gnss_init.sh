#!/bin/bash

SERIAL_PORT="/dev/cuaU1.6"
TEMP_INPUT="/tmp/serial_input.txt"
TEMP_OUTPUT="/tmp/serial_output.txt"
LOG_FILE="/var/log/serial_log.txt"

send_and_capture() {
    local command="$1"
    
    /usr/bin/printf "%s\r\n" "$command" > $SERIAL_PORT
    
    /bin/cat $SERIAL_PORT > $TEMP_OUTPUT
    
    /bin/cat $TEMP_OUTPUT >> $LOG_FILE
}


/bin/rm -f $TEMP_INPUT $TEMP_OUTPUT

/bin/stty -f $SERIAL_PORT 9600

send_and_capture AT'$'GPSP=0
send_and_capture AT'$'GPSNMUN=2,1,1,1,1,1,1
send_and_capture AT'$'GPSNMUNEX=1,1,1
send_and_capture AT'$'AGPSEN=0
send_and_capture AT'$'GNSSCONF=6
send_and_capture AT'$'LCSLPP=2
send_and_capture AT'$'LCSAGLO=8
send_and_capture AT'$'GPSANTPORT=3
send_and_capture AT'$'GPSP=1
send_and_capture AT

/bin/rm -f $TEMP_INPUT $TEMP_OUTPUT
