#include <bits/stdc++.h>
using namespace std;

int idx;
int N; //records에서 중복을 제거한 차량의 개수

//{차량번호, 누적 주차 시간}
class info {
public:
    string num;
    int time;
}infos[1005];

bool cmp(const info& i1, const info& i2) {
    return i1.num < i2.num;
}

int calc(string inTime, string outTime) {
    pair<int,int> in = { stoi(inTime.substr(0, 2)), stoi(inTime.substr(3, 2)) };
    pair<int,int> out = { stoi(outTime.substr(0, 2)), stoi(outTime.substr(3, 2)) };
    // cout<<in.first<<" "<<in.second<<" "<<out.first<<" "<<out.second<<'\n';
    
    if(in.first == out.first) {
        return out.second - in.second;
    }
    
    int ret = 0;
    ret += (60 - in.second);
    ret += (out.second);
    ret += ( (out.first) - (in.first + 1) ) * 60;
    
    return ret;
}

void update(string carNum, int amount) {
    for(int i=0; i<N; i++) {
        if(infos[i].num == carNum) {
            infos[i].time += amount;
            return;
        }
    }
    
    infos[idx++] = {carNum, amount};
    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    //중복 제거한 차량 번호의 개수 계산
    set<string> s;
    for(const auto& record : records) {
        s.insert(record.substr(6, 4));
    }
    N = (int)s.size();
    
    //차량 기록들을 보면서 누적 시간 계산
    map<string, string> mp;
    for(const auto& record : records) {
        string time = record.substr(0, 5);
        string num = record.substr(6, 4);
        string type = record.substr(11, 3);
        // cout << time <<" "<<num <<" "<<type <<"\n";
        
        if(type == "IN") {
            mp.insert({num, time});
        }else {
            string Intime = mp[num];
            //OUT이므로 time은 OutTime
            int res = calc(Intime, time);
            // cout<<num<<" "<<res<<"\n";
            //Infos 배열에 업데이트하기
            update(num, res);
            //map에서 정보 제거
            mp.erase(num);
        }
    }
    
    //23:59분 기준으로 아직 남아있는 차들까지 고려하여 계산
    for(const auto& car : mp) {
        //car은 pair<string, string> 으로 {차량번호, 입차 시각임}
        int res = calc(car.second, "23:59");
        update(car.first, res);
    }
    
    //infos 배열 차량번호 기준으로 정렬
    sort(infos, infos+N, cmp);
    
    //차량 번호가 작은 자동차부터 청구할 주차요금을 담아 리턴
    vector<int> ans;
    for(int i=0; i<N; i++) {
        //{num, time} = 차량번호, 누적 주차 시각
        info cur = infos[i];
        
        int fee = fees[1];
        
        if(cur.time > fees[0]) {
            int exceed = cur.time - fees[0];
            // cout<<exceed<<'\n';
            int tmp = (exceed % fees[2] == 0) ? exceed/fees[2] : (exceed+fees[2] - (exceed%fees[2]))/fees[2];
            // cout<<tmp<<'\n';
            fee += (fees[3]) * tmp;
        }
        
        ans.push_back(fee);
    }
    
    return ans;
    
}
