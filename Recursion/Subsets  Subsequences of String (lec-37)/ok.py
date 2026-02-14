def solve(s, output, index, ans):
    if index >= len(s):
        if output:
            ans.append(output)
        return

    # Exclude
    solve(s, output, index + 1, ans)

    # Include
    solve(s, output + s[index], index + 1, ans)

def subsequences(s):
    ans = []
    solve(s, "", 0, ans)
    return ans

# Driver code
s = "abc"
result = subsequences(s)

print("All non-empty subsequences:")
for item in result:
    print(item)
