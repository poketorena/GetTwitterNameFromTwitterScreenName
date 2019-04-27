#include <Siv3D.hpp>

void Main()
{
    const Font font(30);

    while (System::Update())
    {
        String screenName = L"science507";

        HTTPClient client;

        const String url = L"https://twitter.com/" + screenName;

        String filePath = L"test.txt";

        client.download(url, filePath);

        TextReader reader(L"test.txt");

        const String s = reader.readAll();

        int firstIndex = s.indexOf(L"ProfileHeaderCard-nameLink u-textInheritColor js-nav");

        int lastIndex = s.indexOf(L"<", firstIndex);

        String name = s.substr(firstIndex + 54, lastIndex - (firstIndex + 54));

        Println(name);

        WaitKey();
    }
}
