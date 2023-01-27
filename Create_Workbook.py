import requests
import sys
from bs4 import BeautifulSoup

### stdout Ridirection 
sys.stdout = open("./result.txt", 'w', encoding='UTF-8')

headers = {'User-Agent' : 'Mozilla/5.0'}
url = "https://www.acmicpc.net/workbook/view/7645"
res = requests.get(url, headers=headers)
res.raise_for_status()

soup = BeautifulSoup(res.text, "lxml")

result = []
result.append("| 문제 | 문제 제목 | 정답 코드 |")
result.append("| :--: | :--: | :--: |")

problems = soup.find("div", attrs={"class":"table-responsive"}).find("tbody").findAll("tr")

for problem in problems :
    problemInfo = problem.findAll("td")

    problemNum = ""
    problemName = ""
    problemState = "| [미완료] |"
    for idx, elem in enumerate(problemInfo) :
        if idx == 0 : problemNum = elem.getText()
        if idx == 1 :
            elem = elem.find("a")
            problemName = elem.getText()
        if idx == 2 :
            ### 로그인 후 크롤링
            # problemState = "| [완료](./solutions/" + problemNum + ".cpp) |"
            # 2023.01.27 : BOJ는 공식적으로 프로그램을 통한 로그인 허용하지 않아 로그인 작업을 할 수 없음을 확인하여 삭제

    problemLink = "https://www.acmicpc.net/problem/"+problemNum

    temp = "| " + problemNum + " | [" + problemName + "]("+problemLink+")" + problemState
    result.append(temp)

for elem in result :
    print(elem)
