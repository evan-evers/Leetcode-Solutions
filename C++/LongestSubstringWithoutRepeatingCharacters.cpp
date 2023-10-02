//Original problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestSubstring(string s) {
  //sliding window solution: iterate through the string, and whenever a repeat character is found, move the left end of the substring past the leftmost repeat character
  int max_length = 0;
  string substring = "";

  for (int i = 0; i < s.length(); i++) {
  substring += s[i];  //add next character to the substring

    for (int j = 0; j < substring.length() - 1; j++) {
      if (s[i] == substring[j]) { //if a duplicate character is found
        substring = substring.substr(j + 1,substring.length() - (j + 1)); //set substring to be everything between the two repeating characters, plus the right repeat character
        break;	//no need to check the rest of the characters
      }
    }

    max_length = max(max_length, int(substring.length()));    //store the biggest substring size found
  }
        
  return max_length;
}
