// Bruteforce solution using java

class Solution {
    public List<String> commonChars(String[] A) {
		int n = A.length;
		ArrayList<HashMap<Character, Integer>> freq = new ArrayList<>();
		ArrayList<Character> charList = new ArrayList<>();

		for (String word: A) {
			HashMap<Character, Integer> charFreq = new HashMap<>();

			for (char c: word.toCharArray())
				charFreq.put(c, charFreq.getOrDefault(c, 0) + 1);

			freq.add(charFreq);
		}

		for (char c: "abcdefghijklmnopqrstuvwxyz".toCharArray()) {
			int presentInAll = 10000000;
			for (int i = 0; i < n; i += 1) {
				if (!freq.get(i).containsKey(c))
					presentInAll = 0;
				else 
					presentInAll = Math.min(presentInAll, freq.get(i).get(c));
			}

			if (presentInAll == 0)
				continue;

			for (int i = 0; i < n; i += 1)
				freq.get(i).put(c, freq.get(i).get(c) - presentInAll);

			for (int i = 0; i < presentInAll; i += 1)
				charList.add(c);
			
		}

		// return new List.of(charList);
		return charList.stream().map(x -> String.valueOf(x)).collect(Collectors.toList());

    }
}