## 백준 문제집 페이지를 Crawling 하여 Github upload 형식으로 만드는 코드.

import requests
import sys
from bs4 import BeautifulSoup

### stdout Ridirection 
### Refer : https://24hours-beginner.tistory.com/115
sys.stdout = open("./result.txt", 'w', encoding='UTF-8')

url = "https://www.acmicpc.net/workbook/view/12441"
res = requests.get(url)
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
            ### 동적 크롤링 (Selenium 으로 성공인 경우는 아래와 같이 생성하도록 변경해야함.)
            # problemState = "| [완료](./solutions/" + problemNum + ".cpp) |"
            pass

    problemLink = "https://www.acmicpc.net/problem/"+problemNum
    
    temp = "| " + problemNum + " | [" + problemName + "]("+problemLink+")" + problemState
    result.append(temp)

for elem in result :
    print(elem)
