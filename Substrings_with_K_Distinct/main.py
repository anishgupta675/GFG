class Solution:
    def count_substrings_with_k_distinct_characters(self, s, k):
        count = 0  # Initialize a counter for the substrings
        character_count = dict()  # Initialize a dictionary to track character counts
        start_index = 0  # Initialize the starting index of the current substring


        for end_index in range(len(s)):
            character_count[s[end_index]] = character_count.get(s[end_index], 0) + 1


            while len(character_count) > k:
                # Remove characters from the start of the substring until we have 'k' distinct characters
                first_char = s[start_index]
                if character_count[first_char] == 1:
                    del character_count[first_char]
                else:
                    character_count[first_char] -= 1
                start_index += 1


            count += (end_index - start_index + 1)  # Increment the count based on substring length


        return count
   
    def substrCount (self,s, k):
        return self.count_substrings_with_k_distinct_characters(s, k) - self.count_substrings_with_k_distinct_characters(s, k - 1)