#include<iostream>
#include<cstdlib>
using namespace std;
int getmax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 0;i < n;i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countsort(int arr[], int n, int exp)
{
	int output[30];
	int i, count[30] = {0};
	for (i = 0;i < n;i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1;i < 30;i++)
		count[i] += count[i-1];
	for (i = n - 1;i >= 0;i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0;i < n;i++)
		arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
	int m = getmax(arr , n);
	for (int exp = 1;m / exp > 0;exp *= 10)
		countsort(arr, n, exp);
}
void print(int arr[], int n)
{
	for (int i = 0;i < n;i++)
		cout << arr[i] << " ";
}
int main()
{

int arr[20];
for(int j=0;j<20;j++)
{
arr[j]=rand()%100;
}
cout<<"\n\n Original Array  :";
for(int i=0;i<20;i++)
cout<<arr[i]<<" ";
cout<<endl;

int n = sizeof(arr) / sizeof(arr[0]);
radixsort(arr, n);
cout<<"\n\n  After Sorting  :";
print(arr, n);
return 0;
}

