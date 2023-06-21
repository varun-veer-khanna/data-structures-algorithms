'''Simplify a given algebraic string of characters, 
‘+’, ‘-‘ operators and parentheses. 
Output the simplified string without parentheses.'''


def remove_brackets(string):
    result_string=""
    sign_stack=[0] # 0 for positive and 1 for negative
    brace_stack=[0] # 0 for opening and 1 for closing
    if string:
        for i in range(0, len(string)):
            if sign_stack[-1]==1 and brace_stack[-1]==0:
                # means that there is an opening brace and a negative sign before it
                # would require toggling of the signs which are to be subsequently processed
                if string[i]=='-':
                    result_string=result_string+"+"
                    sign_stack.append(1)
                elif string[i]=='(':
                    brace_stack.append(0)
                elif string[i]=='+':
                    result_string=result_string+"-"
                    sign_stack.append(0)
                elif string[i]==')':
                    brace_stack.append(1)
                    sign_stack.pop()
                else:
                    result_string=result_string+string[i] 
            else:
                if string[i]=='-':
                    result_string=result_string+"-"
                    sign_stack.append(0)
                elif string[i]=='(':
                    brace_stack.append(0)
                elif string[i]=='+':
                    result_string=result_string+"+"
                    sign_stack.append(1)
                elif string[i]==')':
                    brace_stack.append(1)
                    sign_stack.pop()
                else:
                    result_string=result_string+string[i]
    return result_string
            


if __name__=='__main__':
    string="a-(b-c-(d+e))-f"
    result_string=remove_brackets(string)
    print(result_string)