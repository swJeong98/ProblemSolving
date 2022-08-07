def solution(N, stages):
    answer = []
    total_challange = [0 for i in range(N+5)] #stage 별 도달한 유저의 수 저장
    do_challange = [0 for i in range(N+5)] # stage 에서 실패한 유저의 수 저장
    
    #INPUT
    for stage in stages :
        if stage != N+1 : do_challange[stage] += 1
	
        # 구간 [1, N] 에 모두 접근해 1을 더하지 않음.
        if stage == N+1 :
            total_challange[1] += 1
            total_challange[N+1] -= 1
            continue

        # stage != N+1, [1, stage]에 모두 접근해 1을 더하지 않음.
        total_challange[1] += 1
        total_challange[stage+1] -= 1
    
		#앞서 언급한 '어떤 작업'에 해당.
    for stage in range(1, N+1) :
        total_challange[stage] += total_challange[stage-1]
    ## 위 작업이 끝나고 나서, total_challange에는
		## stage별 도전 횟수가 정확히 계산되어 있음. 따라서 실패율을 계산함.

    #Calculate Failure Possibility
    result_tuple = []
    for i in range(N+1) : 
        if i == 0 : continue
        tmp = -1
        if total_challange[i] == 0 : tmp = 0
        else : tmp = do_challange[i]/total_challange[i]
        result_tuple.append( (tmp, i) )
        
    #Sorting
    result_tuple.sort(key=lambda x:(-x[0],x[1]))
    
    for elem in result_tuple :
        answer.append(elem[1])
    return answer
