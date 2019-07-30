#!/usr/bin/python
#
# Copyright 2018 Ayrton Gomes
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#

from rpc import EngineRPC
from conf import getHttpConf
import json
import pprint

HTTPSERVER_CONF="engine/httpserver/config.json"
host, port = getHttpConf(HTTPSERVER_CONF)
pp = pprint.PrettyPrinter(indent=4)

if __name__ == '__main__':
  engine = EngineRPC(
      '127.0.0.1', 
      port,
      'user1', 
      'p123'
  )

  result = engine.rpc('engine.ping', [])
  print "RPC[Response] = "
  print json.dumps(result)
