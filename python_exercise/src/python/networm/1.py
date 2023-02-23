from time import process_time_ns
import urllib.request as r

response = r.urlopen("http://www.baidu.com")

print(response.read().decode("utf-8"))