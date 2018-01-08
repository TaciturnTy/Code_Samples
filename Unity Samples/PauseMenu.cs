using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using System.Collections;

//This class controls the displaying and hiding of the pause menu when esc is pressed
//as well as stopping camera movement, time, and presenting the cursor.
public class PauseMenu : MonoBehaviour
{
    public bool pauseMenuOpen = false;
    public GameObject PausePanel;
    public GameObject CustomizePanel;
    public GameObject OptionsPanel;
    public GameObject WinPanel;

    //called once when loaded
    void Start ()
    {
        GetComponent<MouseOrbitImproved>().xSpeed = PlayerSettings.GetPrefXSensitivity();
        GetComponent<MouseOrbitImproved>().ySpeed = PlayerSettings.GetPrefYSensitivity();
        pauseMenuOpen = false;
        Cursor.visible = false;
        Time.timeScale = 1;
    }
	
    //called every frame
	void Update ()
    {
        if (Input.GetKeyDown("escape"))
        {
            if(WinPanel.activeSelf == true)
            {
                return;
            }
            else if (pauseMenuOpen == true)
            {
                pauseMenuOpen = false;

                PausePanel.SetActive(false);
                CustomizePanel.SetActive(false);
                OptionsPanel.SetActive(false);

                GetComponent<MouseOrbitImproved>().xSpeed = PlayerSettings.GetPrefXSensitivity();   
                GetComponent<MouseOrbitImproved>().ySpeed = PlayerSettings.GetPrefYSensitivity();
                Time.timeScale = 1;
                Cursor.visible = false;
                GameObject.FindGameObjectWithTag("Player").GetComponent<Jump_Score_Collect>().MenuOpen = false;
            }
            else
            {
                pauseMenuOpen = true;

                PausePanel.SetActive(true);
                
                GetComponent<MouseOrbitImproved>().xSpeed = 0f;     
                GetComponent<MouseOrbitImproved>().ySpeed = 0f;
                Time.timeScale = 0;
                Cursor.visible = true;
                GameObject.FindGameObjectWithTag("Player").GetComponent<Jump_Score_Collect>().MenuOpen = true;
            }
        }
    }
    
    //function for when Resume is clicked
    public void ResumeButton()
    {
        pauseMenuOpen = false;

        PausePanel.SetActive(false);
        CustomizePanel.SetActive(false);
        OptionsPanel.SetActive(false);

        GetComponent<MouseOrbitImproved>().xSpeed = PlayerSettings.GetPrefXSensitivity();
        GetComponent<MouseOrbitImproved>().ySpeed = PlayerSettings.GetPrefYSensitivity();
        Time.timeScale = 1;
        Cursor.visible = false;

        GameObject.FindGameObjectWithTag("Player").GetComponent<Jump_Score_Collect>().MenuOpen = false;
    }

    //function for when Customize is clicked
    public void CustomizeButton()
    {
        PausePanel.SetActive(false);
        CustomizePanel.SetActive(true);
    }

    //function for when Options is clicked
    public void OptionsButton()
    {
        PausePanel.SetActive(false);
        OptionsPanel.SetActive(true);
    }

    //function for when Back is clicked
    public void BackButton()
    {
        CustomizePanel.SetActive(false);
        OptionsPanel.SetActive(false);
        PausePanel.SetActive(true);
    }
}

