from urllib import response
import urllib.request
import urllib.parse
import json

content = input("what do you want to translate? ")

url = 'https://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule'


head = {}
head['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.102 Safari/537.36 Edg/104.0.1293.63'
data = {}

data['i']: content
data['from'] = 'AUTO'
data['to'] = 'AUTO'
data['smartresult'] = 'dict'
data['client'] = 'fanyideskweb'
data['salt'] = '16615003886648'
data['sign'] = '4fa092c8caf4b058232b4e62b51bf64b'
data['lts'] = '1661500388664'
data['bv'] = 'fbbbd0029d7a274a9c986ae5ed4a4663'
data['doctype'] = 'json'
data['version'] = '2.1'
data['keyfrom'] = 'fanyi.web'
data['action'] = 'FY_BY_REALTlME'

data = urllib.parse.urlencode(data).encode('utf-8')

response = urllib.request.urlopen(url, data, head)
html = response.read().decode('utf-8')

target = json.loads(html)
print('result is: %s' % (target['translateResult'][0][0]['tgt']))
