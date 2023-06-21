'''Simplify a given algebraic string of characters, 
‘+’, ‘-‘ operators and parentheses. 
Output the simplified string without parentheses.'''

def remove_brackets(string):
    result_string=""
    sign_stack=[0] # 0 for positive and 1 for negative
    
    if string:
        #traversing the entire range of the string
        for i in range(0, len(string)):
            # braces and the sign before it play a role in deciding if the subsequent
            # signs have to be toggled or not
            if string[i]=='(':
                if string[i-1]=='+':
                    #setting the flag for a positive sign
                    sign_stack.append(0)
                elif string[i-1]=='-':
                    #setting the flag for a negative sign
                    sign_stack.append(1)
            # the role of a previous opening brace ends with a closing brace
            # hence, popping the previous sign flag before the opening brace
            elif string[i]==')':
                sign_stack.pop()
            # for all other characters
            else:
                # if the sign is positive and the sign flag is negative
                # toggling is required
                if string[i]=='+' and sign_stack[-1]==1:
                    result_string=result_string+'-'
                    # alongwith toggling, the toggled sign must
                    # be stored in the original string to guide 
                    # oncoming opening braces
                    string = string[:i] + '-' + string[i+1:]
                    # as the sign in the original string is changed,
                    # so must the sign flag
                    sign_stack[-1]=0
                elif string[i]=='-' and sign_stack[-1]==1:
                    result_string=result_string+'+'
                    string = string[:i] + '+' + string[i+1:]
                    sign_stack[-1]=1
                # if the character is anything else
                else:
                    result_string=result_string+string[i]
                
    return result_string
            


if __name__=='__main__':
    string="a-(b-c-(d+e))-f"
    result_string=remove_brackets(string)
    print(result_string)