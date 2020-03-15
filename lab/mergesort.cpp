#include<iostream>
using namespace std;

void merge(int nums[],int low,int mid,int high);
void merge_sort(int nums[],int low,int high){
	int mid=(low+high)/2;
    	if(low<high)
    	{	//divide the array
    		merge_sort(nums,low,mid);
    		merge_sort(nums,mid+1,high);
		//merge the array
		merge(nums,low,mid,high);
   	}
	return;	
}
void merge(int nums[],int low,int mid,int high)
{
	int size_a=mid-low+1,size_b=high-mid;
	int a[size_a],b[size_b];
	for(int i=0;i<size_a || i<size_b;i++){
		if(i<size_a) a[i]=nums[low+i];
		if(i<size_b) b[i]=nums[mid+1+i];
	}
	int j=0,i=0;
	//merge
	while(i<size_a || j<size_b){
		if((i<size_a && j<size_b && a[i]<b[j]) || (i<size_a && j>=size_b)) { nums[low++]=a[i++];}
		else nums[low++]=b[j++];
	}
	return;
}
int main(){
	int nums[]={2,1,2,1,2,1};
	merge_sort(nums,0,5);
	for(auto& i:nums) cout<<i<<" ";
	return 0;
}
