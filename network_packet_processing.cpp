#include<iostream>
#include<queue>
#include<vector>

struct Request {
    int arrival_time;
    int process_time;

    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}
};


struct Response{
	bool dropped;
	int start_time;
	Response(bool drop, int start_time)
		:dropped(drop), start_time(start_time)
	{}
};

class Buffer{
private:
	int size;
	std::queue<int> finish_time;
public:
	Buffer(int size)
		: size(size), finish_time()
	{}

	Response Process(const Request &request){
		Response re(1,0);
		if(finish_time.empty()){
			re.start_time = request.arrival_time;
			finish_time.push(request.arrival_time + request.process_time);
		}
		else{
			while(finish_time.front() <= request.arrival_time && !finish_time.empty()) {
				finish_time.pop();
			}

			if((int)finish_time.size() == size){
				re.dropped = 1;
				return re;
			}

			if(!finish_time.empty()){
				re.start_time = finish_time.back();
				finish_time.push(finish_time.back() + request.process_time);
			}
			else{
				re.start_time = request.arrival_time;
				finish_time.push(request.arrival_time + request.process_time);
			}
		}
		re.dropped = 0;
		return re;
	}
};


std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}



std::vector<Response> RequestProcess(Buffer* buffer, std::vector<Request> requests){
	std::vector<Response> responses;
	for(int req = 0; req < (int)requests.size(); ++req){
		responses.push_back(buffer -> Process(requests[req]));
	}
	return responses;
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int size; std::cin >> size;
	std::vector<Request> Requests;
	Requests = ReadRequests();

	Buffer buffer(size);
	std::vector<Response> Responses;
	Responses = RequestProcess(&buffer, Requests);
	for(int i = 0; i < (int)Responses.size(); i++){
		std::cout << (Responses[i].dropped  ? -1 : Responses[i].start_time) << std::endl;
	}

}