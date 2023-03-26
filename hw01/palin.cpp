#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int is_palindrome(string line)
{
    int left = 0;
    size_t right = line.length() - 1;

    //유사회문 판별을 위한 임시 left right 값 선언.
    int tempLeft = 0;
    size_t tempRight = 0;

    int result = 1;

    while (left <= right)
    {
        //left 는 한칸 뒤로 right 는 한칸 앞으로 index를 옮기면서 같은지 확인
        if (line[left] == line[right])
        {
            left++;
            right--;
        }
        else
        {
            result++;
            break;
        }
    }

    //하나의 index 를 건너뛰고 좌우를 비교했을 때 같으면 유사회문임.
    //left 의 index 를 건너뛰는 경우와 right 의 index 를 건너뛰는 경우로 case를 나눔.
    if (result > 1)
    {
        tempLeft = left;
        tempRight = right;

        //right 는 그대로 두고 left의 index만 증가시켜줌.
        tempLeft++;
        while (tempLeft < tempRight)
        {
            //회문인지 비교
            if (line[tempLeft] == line[tempRight])
            {
                tempLeft++;
                tempRight--;
            }
            //유사회문이 아닌 경우로 result 값을 증가시켜주고 탈출
            else
            {
                result++;
                break;
            }
        }

        // 다시 left 와 right 값 초기화
        tempLeft = left;
        tempRight = right;

        //left 는 그대로 두고 right 의 index만 감소시켜줌.
        tempRight--;
        while (tempLeft < tempRight)
        {
            //회문인지 비교
            if (line[tempLeft] == line[tempRight])
            {
                tempLeft++;
                tempRight--;
            }
            //유사회문이 아닌 경우로 result 값을 증가시켜주고 탈출
            else
            {
                result++;
                break;
            }
        }
    }
    if (result > 2)
        result--;

    return result;
}

int main()
{

    string input;
    int count = 0;

    cin >> count;

    int result = 0;
    for (int i = 0; i < count; i++)
    {
        cin >> input;
        result = is_palindrome(input);
        cout << result << "\n";
    }

    return 0;
}