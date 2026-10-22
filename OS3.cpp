#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
int n, head, a[20], total;

cout << "Enter number of requests: ";
cin >> n;

cout << "Enter disk requests: ";
for(int i = 0; i < n; i++)
cin >> a[i];

cout << "Enter initial head position: ";
cin >> head;

// FCFS
total = 0;
int pos = head;

for(int i = 0; i < n; i++)
{
total += abs(pos - a[i]);
pos = a[i];
}
cout << "\nFCFS Head Movement = " << total;

// SSTF
int b[20], done[20] = {0};
for(int i = 0; i < n; i++)
b[i] = a[i];

total = 0;
pos = head;

for(int i = 0; i < n; i++)
{
int minDist = 9999, index = -1;

for(int j = 0; j < n; j++)
{
if(!done[j] && abs(pos - b[j]) < minDist)
{
minDist = abs(pos - b[j]);
index = j;
}
}

total += minDist;
pos = b[index];
done[index] = 1;
}
cout << "\nSSTF Head Movement = " << total;

// SCAN and C-SCAN
sort(a, a + n);

int diskSize = 200;
total = 0;
pos = head;

for(int i = 0; i < n; i++)
if(a[i] >= head)
{
total += abs(pos - a[i]);
pos = a[i];
}

total += abs(pos - (diskSize - 1));
pos = diskSize - 1;

for(int i = n - 1; i >= 0; i--)
if(a[i] < head)
{
total += abs(pos - a[i]);
pos = a[i];
}

cout << "\nSCAN Head Movement = " << total;

total = 0;
pos = head;

for(int i = 0; i < n; i++)
if(a[i] >= head)
{
total += abs(pos - a[i]);
pos = a[i];
}

if(a[0] < head)
{
total += abs(pos - (diskSize - 1));
total += diskSize - 1;
pos = 0;

for(int i = 0; i < n; i++)
if(a[i] < head)
{
total += abs(pos - a[i]);
pos = a[i];
}
}

cout << "\nC-SCAN Head Movement = " << total;

return 0;
}