#!/usr/bin/python3.4

import sys
import json

conf = open("engine/httpserver/config.json")

json_raw = conf.read()
json = json.loads(json_raw)
print("[INFO] httpserver config is loaded")

server_address = json['svr']['bind'][0]

res = server_address.split(":")
host = res[0]
port = int(res[1])

print("httpserver at %s:%s" % (host, port))

