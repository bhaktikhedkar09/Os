#include <iostream>
using namespace std;

int main()
{
int p[] = {1, 2, 3, 2, 4, 1, 5};
int n = 7, f = 3;

for (int type = 1; type <= 3; type++)
{
int frame[3] = {-1, -1, -1};
int time[3] = {0, 0, 0};
int faults = 0, hits = 0, t = 0;

if (type == 1) cout << "\nFIFO\n";
if (type == 2) cout << "\nLRU\n";
if (type == 3) cout << "\nOPTIMAL\n";

for (int i = 0; i < n; i++)
{
int pos = -1;

for (int j = 0; j < f; j++)
if (frame[j] == p[i])
pos = j;

if (pos != -1)
{
hits++;
time[pos] = ++t;
}
else
{
faults++;
pos = -1;

for (int j = 0; j < f; j++)
if (frame[j] == -1)
{
pos = j;
break;
}

if (pos == -1)
{
if (type == 1)
{
pos = 0;
for (int j = 1; j < f; j++)
if (time[j] < time[pos])
pos = j;
}
else if (type == 2)
{
pos = 0;
for (int j = 1; j < f; j++)
if (time[j] < time[pos])
pos = j;
}
else
{
int far = -1;

for (int j = 0; j < f; j++)
{
int k;
for (k = i + 1; k < n; k++)
if (p[k] == frame[j])
break;

if (k > far)
{
far = k;
pos = j;
}
}
}
}

frame[pos] = p[i];
time[pos] = ++t;
}

cout << p[i] << " : ";
for (int j = 0; j < f; j++)
{
if (frame[j] == -1) cout << "- ";
else cout << frame[j] << " ";
}

if (pos != -1 && frame[pos] == p[i])
cout << (faults + hits == i + 1 && faults > 0 &&
hits == 0 ? "Fault" : "");
cout << endl;
}

cout << "Page Faults = " << faults << endl;
cout << "Page Hits = " << hits << endl;
}

return 0;
}