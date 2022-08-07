def solution(answers):
    answer = []
    
    N = len(answers)
    board_a = [0 for i in range(N+5)]
    board_b = [0 for i in range(N+5)]
    board_c = [0 for i in range(N+5)]
    
    #수포자 1
    cur = 1
    for i in range(N) :
        board_a[i] = cur
        cur += 1
        if cur == 6 : cur = 1
        
    # 수포자 2
    cur = 1
    for i in range(N) : 
        if i%2 == 0 : 
            board_b[i] = 2
            continue
        else : board_b[i] = cur
        cur += 1
        if cur == 2 : cur = 3
        if cur == 6 : cur = 1
        
    # 수포자 3
    dir = [3,1,2,4,5]
    for i in range(N) :
        idx = (i // 2) % 5
        board_c[i] = dir[idx]
    
    cnt_a, cnt_b, cnt_c = 0, 0, 0
    for i in range(N) :
        if answers[i] == board_a[i] : cnt_a += 1
        if answers[i] == board_b[i] : cnt_b += 1
        if answers[i] == board_c[i] : cnt_c += 1

    mx = -1
    if mx < cnt_a :
        mx = cnt_a
        while answer : answer.pop()
        answer.append(1)
    
    if mx < cnt_b :
        mx = cnt_b
        while answer : answer.pop()
        answer.append(2)
    elif mx == cnt_b :
        answer.append(2)
    
    if mx < cnt_c :
        mx = cnt_c
        while answer : answer.pop()
        answer.append(3)
    elif mx == cnt_c :
        answer.append(3)
    
    answer.sort()
    return answer
