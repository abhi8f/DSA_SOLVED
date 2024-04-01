public class Codec {
    private ArrayList<String> numToString = new ArrayList<>();
    int i = -1;

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        i++;
        numToString.add(longUrl);
        return String.valueOf(i);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return numToString.get(Integer.valueOf(shortUrl));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
