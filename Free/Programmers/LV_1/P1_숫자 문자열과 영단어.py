def isValid(s) :
    return s == 'zero' or s == 'one' or s=='two' or s=='three' or s=='four'or s=='five' 
    or s=='six' or s=='seven' or s=='eight' or s=='nine'

def Convert(s) :
    dic = {'zero' : 0, 'one' : 1, 'two' : 2, 'three' : 3, 'four' : 4,
          'five' : 5, 'six' : 6, 'seven' : 7, 'eight' : 8, 'nine' : 9}
    return dic[s]

def solution(s):
    answer = 0
    if s.isdigit() :
        return int(s)

    final = ""
    tmp = ""
    for ch in s :
        if ch.isdigit() :
            final += ch
        else :
            tmp += ch
            if isValid(tmp) :
                final += str(Convert(tmp))
                tmp = ""
    answer = int(final)
    return answer
