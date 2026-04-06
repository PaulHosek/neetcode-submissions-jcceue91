from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_map = defaultdict(list);
        for s in strs:
            # make binary represenation
            bin_repr = [0]*26
            for c in s:
                bin_repr[ord(c) - ord('a')] += 1

            anagrams_map[tuple(bin_repr)].append(s)
        return anagrams_map.values() 