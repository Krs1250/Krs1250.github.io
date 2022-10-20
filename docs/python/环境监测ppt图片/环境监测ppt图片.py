import requests
import re
import os
path=r'./compile.txt'

with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

t = '<img src="(.*?)" style="position: absolute; width: 840px; height: 630px;">'
result = re.findall(t, text)

a = 227
for i in result:
    img_url = 'https://docs.ulearning.cn/' + i
    print(img_url + '\n')
    res = requests.get(img_url)
    print(res.status_code)
    print(a)
    with open('./3 第三章 大气和废气监测/' + str(a) + '.png', mode='wb') as f:
        f.write(res.content)
    a += 1

