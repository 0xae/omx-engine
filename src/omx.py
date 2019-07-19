#!/usr/bin/python3.4

import sys
import json
from conf import getConf

HTTPSERVER_CONF="engine/httpserver/config.json"
host,port = getHttpConf(HTTPSERVER_CONF)

print("httpserver at %s:%s" % (host, port))

