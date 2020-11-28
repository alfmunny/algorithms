def kmp(s, ss):
  dp = [0] * len(s)
  j = 0
  i = 1
  while i < len(s):
    if s[i] == s[j]:
      j += 1
      dp[i] = j
    elif j > 0:
      j = dp[j-1]
      i -= 1
    i += 1


  i = j = 0

  while i < len(ss):
    if ss[i] == s[j]:
      j += 1
      if j == len(s):
        j = 0
        print(i)
    elif j > 0:
      j = dp[j-1]
      i -= 1

    i += 1

  return False


print(kmp("aaccd", "aiajdsoasijdoaisjdaaccdaso9ei0923jraaccdsijd"))

