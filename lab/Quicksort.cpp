#include<iostream>
using namespace std;
//Quicksort
void Quicksort(int nums[],int low,int high){
	int pos=low,track=low,iter=low+1;
	if(low<=high){
		//finding correct position for first value

		while(iter<=high){
			if(nums[pos]>nums[iter]){
				swap(nums[track],nums[iter]);
				if(pos!=track) swap(nums[iter],nums[pos]);
				pos=iter;
				track++;
			}
			iter++;
		}
		swap(nums[pos],nums[track]);
		pos=track;
		//partition into two array
		Quicksort(nums,low,pos-1);
		Quicksort(nums,pos+1,high);
	}
	return;
}

int main(){
	int nums[]={24,19,25,26,5,4};
	Quicksort(nums,0,5);

	for(auto& i:nums) cout<<i<<" ";

	return 0;
}
