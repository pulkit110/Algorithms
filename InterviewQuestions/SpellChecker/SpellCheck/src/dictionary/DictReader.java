package dictionary;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

/**
 * @author pulkit
 *
 */
public class DictReader {
	private Set<String> wordList;

	public void setWordList(Set<String> wordList) {
		this.wordList = wordList;
	}

	public Set<String> getWordList() {
		return wordList;
	}
	
	public void readWordList(File f) {
		wordList = new HashSet<String>();
		BufferedReader input;
		
		try {
			input = new BufferedReader(new FileReader(f));
			String line = null;
			while (( line = input.readLine()) != null){
				wordList.add(line);
			}
		} catch (FileNotFoundException e) {
			System.err.println("File not found!");
			e.printStackTrace();
		}  catch (IOException e) {
			System.err.println("Error while reading from file!");
			e.printStackTrace();
		}
	}

	public boolean contains(String word) {
		if (wordList != null) {
			return (wordList.contains(word));
		}
		return false;
	}
}
