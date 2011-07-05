/**
 * 
 */
package spellcheckertester;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

/**
 * @author pulkit
 *
 */
public class SpellCheckerTester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader input = new BufferedReader(new InputStreamReader(
				System.in));

		String line = null;
		try {
			while ((line = input.readLine()) != null) {
				generateIncorrectWords(line, 5, 0);
			}
		} catch (IOException e) {
			System.err.println("Error while reading from Input Stream!");
			e.printStackTrace();
		}
	}

	private static void generateIncorrectWords(String word, int depth, int index) {
		if (word == null) {
			return;
		}
		System.out.println(word);
		if (depth > 0 && index < word.length()) {
			String caseChangedWord = StringUtils.changeCaseAt(word, index);
			String repeatedLettersWord = StringUtils
					.RepeatLettersAt(word, index);
			List<String> vowelChangedWords = StringUtils.changeVowelsAt(word,
					index);
			
			generateIncorrectWords(caseChangedWord, depth-1, index+1);
			generateIncorrectWords(repeatedLettersWord, depth-1, index+1);
			for (String vowelChangedWord : vowelChangedWords) {
				generateIncorrectWords(vowelChangedWord, depth-1, index+1);
			}
		}
	}
}
