import socket
import random
import time

wr_port, rd_port = 11234, 11235

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
	print ("press ctrl+c to exit")
	s.bind(("", rd_port))
	s.setblocking(0)
	s.settimeout(0.5)
	host = s.getsockname()[0]
	while 1:
		data = str(random.randint(0, 100)) + "\n"
		s.sendto(data.encode("utf-8") , (host, wr_port))
		time.sleep(1)
		try:
			recv_data, addr = s.recvfrom(1024)
			if len(recv_data) > 0:# and addr == rd_port:
				print("recieved", addr, recv_data.decode("utf-8"))
		except socket.timeout as e:
			pass
