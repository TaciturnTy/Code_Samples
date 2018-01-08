using UnityEngine;
using System.Collections;

//This class will deal with storing unlockable items and the settings that the player makes.

//These methods are merely for storage and retrieval, a static class such as this cannot 
//be called from buttons so it falls upon MainMenuFunctions to apply the settings.

public class PlayerSettings : MonoBehaviour {

    public static int BALL_MATERIAL;
    public static int HIGHEST_LEVEL;
    public static float MUSIC_VOLUME;
    public static int HARDMODE_ENABLED; //0 no, 1 yes
    //public static int SFX_VOLUME;
    public static float X_CAMERA_SENSITIVITY;
    public static float Y_CAMERA_SENSITIVITY;
    public static int VIDEO_SETTINGS;

    void Awake()
    {
        SetInitialValues();

        BALL_MATERIAL = PlayerPrefs.GetInt("ball_material");
        HIGHEST_LEVEL = PlayerPrefs.GetInt("highest_level");
        MUSIC_VOLUME = PlayerPrefs.GetFloat("music_volume");
        HARDMODE_ENABLED = PlayerPrefs.GetInt("hardmode_enabled");
        X_CAMERA_SENSITIVITY = PlayerPrefs.GetFloat("x_camera_sensitivity");
        Y_CAMERA_SENSITIVITY = PlayerPrefs.GetFloat("y_camera_sensitivity");
        VIDEO_SETTINGS = PlayerPrefs.GetInt("video_settings");
    }
    void Start()
    {
        //SetInitialValues();

        //BALL_MATERIAL = PlayerPrefs.GetInt("ball_material");
        //HIGHEST_LEVEL = PlayerPrefs.GetInt("highest_level"); 
        //MUSIC_VOLUME = PlayerPrefs.GetFloat("music_volume"); 
        //X_CAMERA_SENSITIVITY = PlayerPrefs.GetFloat("x_camera_sensitivity"); 
        //Y_CAMERA_SENSITIVITY = PlayerPrefs.GetFloat("y_camera_sensitivity"); 
        //VIDEO_SETTINGS = PlayerPrefs.GetInt("video_settings");
    }

    void Update ()
    {

	}

    //SET METHODS
    void SetInitialValues()
    {
        int hasPlayed = PlayerPrefs.GetInt("has_played");

        if (hasPlayed == 0)
        {
            BALL_MATERIAL = 1;
            PlayerPrefs.SetInt("ball_material", BALL_MATERIAL);

            HIGHEST_LEVEL = 0;
            PlayerPrefs.SetInt("highest_level", HIGHEST_LEVEL);

            MUSIC_VOLUME = 0.5f;
            PlayerPrefs.SetFloat("music_volume", MUSIC_VOLUME);

            HARDMODE_ENABLED = 0;
            PlayerPrefs.SetInt("hardmode_enabled", HARDMODE_ENABLED);

            X_CAMERA_SENSITIVITY = 120;
            PlayerPrefs.SetFloat("x_camera_sensitivity", X_CAMERA_SENSITIVITY);

            Y_CAMERA_SENSITIVITY = 120;
            PlayerPrefs.SetFloat("y_camera_sensitivity", Y_CAMERA_SENSITIVITY);

            VIDEO_SETTINGS = 2;
            PlayerPrefs.SetInt("video_settings", VIDEO_SETTINGS);

            PlayerPrefs.SetInt("has_played", 1);
        }
    }

    public static void SetPrefBallMaterial(int num)
    {
        BALL_MATERIAL = num;
        PlayerPrefs.SetInt("ball_material", BALL_MATERIAL);
    }

    public static void SetPrefHighestLevel(int level)
    {
        HIGHEST_LEVEL = level;
        PlayerPrefs.SetInt("highest_level", HIGHEST_LEVEL);
    }

    public static void SetPrefMusicVolume(float vol)
    {
        MUSIC_VOLUME = vol;
        PlayerPrefs.SetFloat("music_volume", MUSIC_VOLUME);
    }

    public static void SetPrefHardmodeEnabled(int hard)
    {
        HARDMODE_ENABLED = hard;
        PlayerPrefs.SetInt("hardmode_enabled", HARDMODE_ENABLED);
    }

    public static void SetPrefXSensitivity(float x)
    {
        X_CAMERA_SENSITIVITY = x;
        PlayerPrefs.SetFloat("x_camera_sensitivity", X_CAMERA_SENSITIVITY);
    }

    public static void SetPrefYSensitivity(float y)
    {
        Y_CAMERA_SENSITIVITY = y;
        PlayerPrefs.SetFloat("y_camera_sensitivity", Y_CAMERA_SENSITIVITY);
    }

    public static void SetPrefVideoSettings(int vid)
    {
        VIDEO_SETTINGS = vid;
        PlayerPrefs.SetInt("video_settings", VIDEO_SETTINGS);
    }

    //GET METHODS
    public static int GetPrefBallMaterial()
    {
        return PlayerPrefs.GetInt("ball_material");
    }

    public static int GetPrefHighestLevel()
    {
        return PlayerPrefs.GetInt("highest_level");
    }

    public static float GetPrefMusicVolume()
    {
        return PlayerPrefs.GetFloat("music_volume");
    }

    public static int GetPrefHardmodeEnabled()
    {
        return PlayerPrefs.GetInt("hardmode_enabled");
    }

    public static float GetPrefXSensitivity()
    {
        return PlayerPrefs.GetFloat("x_camera_sensitivity");
    }

    public static float GetPrefYSensitivity()
    {
        return PlayerPrefs.GetFloat("y_camera_sensitivity");
    }

    public static int GetPrefVideoSettings()
    {
        return PlayerPrefs.GetInt("video_settings");
    }
}
