#!/usr/bin/env bash
ps aux | grep omxhttp | awk '{print $2}' | xargs kill -9
