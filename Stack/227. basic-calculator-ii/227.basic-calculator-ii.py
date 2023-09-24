#
# @lc app=leetcode id=227 lang=python3
#
# [227] Basic Calculator II
#

# @lc code=start


class Solution:
    def calculate(self, s: str) -> int:
        # Ealuate RPN from Infix first and then woukld evaluate value based on
        # value calclaution from RPN form
        def evaluate_rpn(rpn):
            stack = []
            for token in rpn:
                if token in {'+', '-', '*', '/'}:
                    num2 = stack.pop()
                    num1 = stack.pop()
                    if token == '+':
                        stack.append(num1 + num2)
                    elif token == '-':
                        stack.append(num1 - num2)
                    elif token == '*':
                        stack.append(num1 * num2)
                    elif token == '/':
                        stack.append(int(num1 / num2))
                else:
                    stack.append(int(token))
            return stack[0]

        operand_st = []
        operator_st = []
        precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
        num = 0

        for ch in s:
            if ch.isdigit():
                num *= 10
                num += int(ch)
            elif ch in {'+', '-', '*', '/'}:
                operand_st.append(str(num))
                num = 0
                while operator_st and precedence[operator_st[-1]] >= precedence[ch]:
                    operand_st.append(operator_st.pop())
                operator_st.append(ch)

        operand_st.append(str(num))
        while operator_st:
            operand_st.append(operator_st.pop())

        result = evaluate_rpn(operand_st)
        return result

# @lc code=end
