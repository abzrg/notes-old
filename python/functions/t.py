import socket

class Resolver:
    def __init__(self):
        self._cache = {}

    def __call__(self, host):
        if host not in self._cache:
            self._cache[host] = socket.gethostbyname(host)
        return self._cache[host]

    # 1
    def __clear__(self):
        self._cache.clear()

    # 2
    def has_host(self, host):
        return host in self._cache
