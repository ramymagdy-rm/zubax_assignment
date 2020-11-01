# task three
the netcat flags "arguments" at the task desciption didn't transmit required writer port, and the following alternative was used to show listener and writer ports
two separate terminal windows of the following commands transmitted and recieved data succssefully
- listener  $ nc -u -l 11234
- writer    $ nc -u localhost 11235
