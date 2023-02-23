from urllib import response
import urllib.request

url = 'http://www.whatismyip.com.tw'
# 代理
proxy_support = urllib.request.ProxyHandler(
    {'http': '47.106.105.236:80'})

opener = urllib.request.build_opener(proxy_support)
urllib.request.install_opener(opener)

response = urllib.request.urlopen(url)
html = response.read().decode('utf-8')

print(html)
