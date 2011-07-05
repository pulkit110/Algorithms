/**
 * 
 */
package spellchecker;

import java.util.ArrayList;
import java.util.List;

/**
 * @author pulkit
 * 
 */
public class StringUtils {

	public static List<String> changeVowelsAt(String s, int pos) {
		List<Character> vowels = new ArrayList<Character>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		List<String> newWords = new ArrayList<String>();
		if (pos < s.length() && vowels.contains(s.charAt(pos))) {
			for (Character v : vowels) {
				if (!v.equals(s.charAt(pos))) {
					newWords.add(replaceCharAt(s, pos, v));
				}
			}
		}
		return newWords;
	}

	public static String removeRepeatedLettersAt(String s, int pos) {
		String newWord = null;
		if (pos < s.length() - 1 && s.charAt(pos) == s.charAt(pos + 1)) {
			newWord = removeCharAt(s, pos);
		}
		return newWord;
	}

	public static String replaceCharAt(String s, int pos, char c) {
		StringBuffer buf = new StringBuffer(s);
		buf.setCharAt(pos, c);
		return buf.toString();
	}

	public static String removeCharAt(String s, int pos) {
		StringBuffer buf = new StringBuffer(s.length() - 1);
		buf.append(s.substring(0, pos)).append(s.substring(pos + 1));
		return buf.toString();
	}

	public static String changeCaseAt(String s, int pos) {
		String newWord = null;
		if (pos < s.length()) {
			if (Character.isUpperCase(s.charAt(pos))) {
				newWord = replaceCharAt(s, pos,
						Character.toLowerCase(s.charAt(pos)));
			} else {
				newWord = replaceCharAt(s, pos,
						Character.toUpperCase(s.charAt(pos)));
			}
		}
		return newWord;
	}

}
