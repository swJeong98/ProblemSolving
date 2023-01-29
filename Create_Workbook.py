import requests
import sys
import os
from bs4 import BeautifulSoup

######################## README ###########################
#                                                         #
#                                                         #
#                       < Notes >                         #
# You must change variables below to get desired result ! #
#                                                         #
# <Mandatory>                                             #
# url : BOJ Workbook URL                                  #
# userIDs : BOJ Handle(s)                                 #                                                     
# prefixPath : directory where solution code is created   #
# file extension : type of solution code                  #
#                                                         #
# <Optioanl>                                              #
# redirect text file name : result.txt -> xxxx.txt        #
#                                                         #
#                                                         #
###########################################################

### stdout Ridirection
### result.txt is necessarily exist in same directory that executed python file exists.
### Or you can designate an absolute path where desired output is redirected.
sys.stdout = open("./result.txt", 'w', encoding='UTF-8')

headers = {'User-Agent' : 'Mozilla/5.0'}

## replace this part with BOJ Workbook URL ##
url = "https://www.acmicpc.net/workbook/view/6782"


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
    ## replace this part with BOJ handle 
    ## example : ['tree5678' , 'tree1234']
    userIDs = ['handle1', 'handle2']

    ## replace this part with path where solution codes are created.
    prefixPath = './TwoPointer/'
    ## replace this part with file extension of your solution.
    fileExtension = '.cpp'

    for idx, elem in enumerate(problemInfo) :
        if idx == 0 :
            problemNum = elem.getText()
            destination = prefixPath + problemNum + fileExtension
            if not os.path.exists(destination) :
                f = open(destination, 'w')
                f.close()

        if idx == 1 :
            elem = elem.find("a")
            problemName = elem.getText()

    for userid in userIDs :
        submit_url = 'https://www.acmicpc.net/status?option-status-pid=on&problem_id=' + problemNum + '&user_id=' + userid + '&language_id=-1&result_id=-1&from_problem=1'

        response = requests.get(submit_url, headers=headers)
        response.raise_for_status()
        tmp = BeautifulSoup(response.text, "lxml")
        submits = tmp.find("table", attrs={"class":"table table-striped table-bordered"}).find("tbody").findAll("tr")
        for submit in submits :
            try :
                submit = submit.findAll("td")
                accept = submit[3].getText()
                if accept == '맞았습니다!!' : problemState = "| [완료](./solutions/" + problemNum + ".cpp) |"
                break
            except : continue

    problemLink = "https://www.acmicpc.net/problem/"+problemNum

    temp = "| " + problemNum + " | [" + problemName + "]("+problemLink+")" + problemState
    result.append(temp)

for elem in result :
    print(elem)