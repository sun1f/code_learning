from urllib import response
import urllib.request
import urllib.parse
import json

content = input("what do you want to translate? ")

url = 'https://fanyi.baidu.com/v2transapi?from=en&to=zh'

head = {}
head['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.102 Safari/537.36 Edg/104.0.1293.63'

data = {}
data['from'] = 'en'
data['to'] = 'zh'
data['query'] = content
data['transtype'] = 'realtime'
data['simple_means_flag'] = '3'
data['token'] = 'b10425a84a35bc7d2b9d531044840505'
data['domain'] = 'common'


data = urllib.parse.urlencode(data).encode('utf-8')

response = urllib.request.urlopen(url, data, head)
html = response.read().decode('utf-8')

print(html)
