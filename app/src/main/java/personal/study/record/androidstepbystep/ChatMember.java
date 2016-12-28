package personal.study.record.androidstepbystep;
/**
 * Created by shenjinqi on 2016/12/27.
 */
public class ChatMember
{
    private String name;
    private int icon;

    public ChatMember(String name, int icon) {
        this.name = name;
        this.icon = icon;
    }

    public String getName() {
        return name;
    }

    public int getIcon() {
        return icon;
    }
}
