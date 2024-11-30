class YoutubeAsync extends AsyncTask<String, Void, String> {
            protected String doInBackground(String... strings) {
                try {
                    URL google = new URL("https://www.youtube.com/watch?v=HMDcwE6SdrM");
                    HttpURLConnection client = (HttpURLConnection) google.openConnection();

                    // on below line setting method as post.
                    client.setRequestMethod("GET");

                    // on below line setting content type and accept type.
                    /*client.setRequestProperty("Content-Type", "application/json");
                    client.setRequestProperty("Accept", "application/json");*/
                    client.setRequestProperty("Accept-Language", "en-US");

                    // on below line setting client.
                    client.setDoOutput(true);
                    BufferedReader in = new BufferedReader(new InputStreamReader(google.openStream()));
                    String input;
                    StringBuffer stringBuffer = new StringBuffer();
                    while ((input = in.readLine()) != null) {
                        stringBuffer.append(input);
                    }
                    in.close();
                    String htmlData = stringBuffer.toString();
                    Log.i("ChatAdapter.java", "the result is: "+ stringBuffer.toString());
                }
                catch (Exception e){
                    Log.i("ChatAdapter.java", "this is just wrong");
                }
                return null;
            }
        }
