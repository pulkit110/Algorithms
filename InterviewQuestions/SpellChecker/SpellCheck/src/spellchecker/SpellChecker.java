/**
 * 
 */
package spellchecker;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

import dictionary.DictReader;

/**
 * @author pulkit
 * 
 */
public class SpellChecker {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		DictReader dictionary = new DictReader();
		File dictionaryFile = new File("/usr/share/dict/words");
		dictionary.readWordList(dictionaryFile);

		suggestWords(dictionary);
	}

	private static void suggestWords(DictReader dictionary) {
		BufferedReader input = new BufferedReader(new InputStreamReader(
				System.in));

		String line = null;
		try {
			System.out.print(">");
			while ((line = input.readLine()) != null) {
				if (dictionary.contains(line)) {
					System.out.println("Correct Word");
				} else {
					System.out.println(findSuggestion(dictionary, line));
				}
				System.out.print(">");
			}
		} catch (IOException e) {
			System.err.println("Error while reading from Input Stream!");
			e.printStackTrace();
		}
	}

	private static String findSuggestion(DictReader dictionary, String word) {
		String suggestedWord;
		for (OperationType ot : OperationType.values()) {
			suggestedWord = wordSuggestor(dictionary, word, 0, ot);
			if (suggestedWord != null) {
				return suggestedWord;
			}
		}
		return "NO SUGGESTION";
	}

	private static String wordSuggestor(DictReader dictionary, String word,
			int index, OperationType nextOperation) {
		if (word == null) {
			return null;
		}
		if (dictionary.contains(word)) {
			return word;
		}
		if (index < word.length()) {
			String suggestedWord;

			switch (nextOperation) {
			case CASE_CHANGE:
				String caseChangedWord = StringUtils.changeCaseAt(word, index);
				for (OperationType ot : OperationType.values()) {
					if (ot != nextOperation) {
						suggestedWord = wordSuggestor(dictionary, caseChangedWord,
								index, ot);
						if (suggestedWord != null) {
							return suggestedWord;
						}
					}
				}
				break;
			case REPEATED_REMOVE:
				String repeatedLettersRemovedWord = StringUtils
						.removeRepeatedLettersAt(word, index);
				for (OperationType ot : OperationType.values()) {
					suggestedWord = wordSuggestor(dictionary,
							repeatedLettersRemovedWord, index, ot);
					if (suggestedWord != null) {
						return suggestedWord;
					}
				}
				break;
			case VOWEL_CHANGE:
				List<String> vowelChangedWords = StringUtils.changeVowelsAt(
						word, index);
				for (OperationType ot : OperationType.values()) {
					if (ot != nextOperation) {
						for (String newWord : vowelChangedWords) {
							suggestedWord = wordSuggestor(dictionary, newWord,
									index, ot);
							if (suggestedWord != null) {
								return suggestedWord;
							}
						}
					}
					
				}
				break;
			case INIT:
				for (OperationType ot : OperationType.values()) {
					suggestedWord = wordSuggestor(dictionary, word, index + 1, ot);
					if (suggestedWord != null) {
						return suggestedWord;
					}
				}
				break;
			}
		}
		return null;
	}
}
