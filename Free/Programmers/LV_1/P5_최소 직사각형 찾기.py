def solution(sizes):
    answer = 0
    mx = max( map(max, sizes) )
    
    tmp = 0 # 명함마다 작은 값들 중 최댓값
    for elem in sizes :
        tmp = max(tmp, min(elem[0], elem[1]))
    
    answer = mx * tmp
    return answer
