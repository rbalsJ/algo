#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int is_palindrome(string line)
{
    int left = 0;
    size_t right = line.length() - 1;

    //����ȸ�� �Ǻ��� ���� �ӽ� left right �� ����.
    int tempLeft = 0;
    size_t tempRight = 0;

    int result = 1;

    while (left <= right)
    {
        //left �� ��ĭ �ڷ� right �� ��ĭ ������ index�� �ű�鼭 ������ Ȯ��
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

    //�ϳ��� index �� �ǳʶٰ� �¿츦 ������ �� ������ ����ȸ����.
    //left �� index �� �ǳʶٴ� ���� right �� index �� �ǳʶٴ� ���� case�� ����.
    if (result > 1)
    {
        tempLeft = left;
        tempRight = right;

        //right �� �״�� �ΰ� left�� index�� ����������.
        tempLeft++;
        while (tempLeft < tempRight)
        {
            //ȸ������ ��
            if (line[tempLeft] == line[tempRight])
            {
                tempLeft++;
                tempRight--;
            }
            //����ȸ���� �ƴ� ���� result ���� ���������ְ� Ż��
            else
            {
                result++;
                break;
            }
        }

        // �ٽ� left �� right �� �ʱ�ȭ
        tempLeft = left;
        tempRight = right;

        //left �� �״�� �ΰ� right �� index�� ���ҽ�����.
        tempRight--;
        while (tempLeft < tempRight)
        {
            //ȸ������ ��
            if (line[tempLeft] == line[tempRight])
            {
                tempLeft++;
                tempRight--;
            }
            //����ȸ���� �ƴ� ���� result ���� ���������ְ� Ż��
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