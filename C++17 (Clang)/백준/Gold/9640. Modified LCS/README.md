# [Gold III] Modified LCS - 9640 

[문제 링크](https://www.acmicpc.net/problem/9640) 

### 성능 요약

메모리: 2212 KB, 시간: 0 ms

### 분류

수학, 브루트포스 알고리즘, 정수론, 유클리드 호제법, 중국인의 나머지 정리

### 제출 일자

2026년 3월 12일 20:50:49

### 문제 설명

<p>LCS stands for longest common subsequence, and it is a well known problem. A sequence in this problem means a list of integers, and a sequence X is considered a subsequence of another sequence Y, when the sequence X can be obtained by deleting zero or more elements from the sequence Y without changing the order of the remaining elements.</p>

<p>In this problem you are given two sequences and your task is to find the length of the longest sequence which is a subsequence of both the given sequences.</p>

<p>You are not given the sequences themselves. For each sequence you are given three integers N , F and D, where N is the length of the sequence, F is the first element in the sequence. Each element except the first element is greater than the element before it by D.</p>

<p>For example N = 5, F = 3 and D = 4 represents the following sequence: [3, 7, 11, 15, 19].</p>

<p>There will be at least one integer which belongs to both sequences and it is not greater than 1,000,000.</p>

### 입력 

 <p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1 ≤ T ≤ 100). Followed by the test cases, each test case is described in one line which contains 6 integers separated by a single space N1 F1 D1 N2 F2 D2 (1 ≤ N1,N2 ≤ 10<sup>18</sup>) and (1 ≤ F1,D1,F2,D2 ≤ 10<sup>9</sup>) representing the length of the first sequence, the first element in the first sequence, the incremental value of the first sequence, the length of the second sequence, the first element in the second sequence and the incremental value of the second sequence, respectively.</p>

### 출력 

 <p>For each test case, print a single line which contains a single integer representing the length of the longest common subsequence between the given two sequences.</p>

